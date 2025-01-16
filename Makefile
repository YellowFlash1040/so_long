# Compiler, Flags and Tools
CC						:= cc
CFLAGS					 = -Wall -Wextra -Werror $(INCLUDES) -g
MLX_FLAGS				:= -lXext -lX11
MAKE					:= make -s

# Output Files
NAME					:= so_long

# Directories
SRC_DIR					:= src
SRC_MAP_DIR				:= $(SRC_DIR)/map
SRC_GUI_DIR				:= $(SRC_DIR)/gui
SRC_SHARED_DIR			:= $(SRC_DIR)/shared
OBJ_DIR					:= obj
MLX_DIR 				:= mlx
LIBS_DIR				:= libraries
LIB_FILE_DIR			:= $(LIBS_DIR)/file
LIB_FT_PRINTF_DIR		:= $(LIBS_DIR)/ft_printf
LIB_GET_NEXT_LINE_DIR	:= $(LIBS_DIR)/get_next_line
LIB_LIST_DIR			:= $(LIBS_DIR)/list
LIB_STRING_DIR			:= $(LIBS_DIR)/ft_string
LIB_CONVERTER_DIR		:= $(LIBS_DIR)/converter

#Additional info
MLX_ORIG_DIR_NAME		:= minilibx-linux
MLX_LIB_NAME			:= libmlx.a

# Includes
INCLUDES				:= -I$(SRC_DIR) \
							-I$(SRC_MAP_DIR) \
							-I$(SRC_GUI_DIR) \
							-I$(SRC_SHARED_DIR) \
							-I$(MLX_DIR) \
							-I$(LIB_FILE_DIR) \
							-I$(LIB_FT_PRINTF_DIR) \
							-I$(LIB_GET_NEXT_LINE_DIR) \
							-I$(LIB_LIST_DIR) \
							-I$(LIB_STRING_DIR) \
							-I$(LIB_CONVERTER_DIR)

# Files
MLX_ARCHIVE				:= mlx.tgz
FILES					:= $(notdir $(wildcard $(SRC_DIR)/*.c)) $(notdir $(wildcard $(SRC_MAP_DIR)/*.c)) $(notdir $(wildcard $(SRC_GUI_DIR)/*.c))

# Objects, Libraries
OBJ						:= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

#External Libraries
LIB_MLX					:= $(MLX_DIR)/libmlx.a
LIB_FILE				:= $(LIB_FILE_DIR)/file.a
LIB_FT_PRINTF			:= $(LIB_FT_PRINTF_DIR)/ft_printf.a
LIB_GET_NEXT_LINE		:= $(LIB_GET_NEXT_LINE_DIR)/get_next_line.a
LIB_LIST				:= $(LIB_LIST_DIR)/list.a
LIB_CONVERTER			:= $(LIB_CONVERTER_DIR)/converter.a

LIBRARIES				:= $(LIB_MLX) \
							$(LIB_FILE) \
							$(LIB_FT_PRINTF) \
							$(LIB_GET_NEXT_LINE) \
							$(LIB_LIST) \
							$(LIB_CONVERTER)

# Colors for Output
GREEN   				:= \033[0;32m
RED						:= \033[31m
RESET   				:= \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(LIBRARIES) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_MAP_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_GUI_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

#Compile Libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null
	@# echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

#Compile MLX
$(LIB_MLX):
	@rm -rf $(MLX_DIR)
	@tar xf $(MLX_ARCHIVE) --transform='s/^$(MLX_ORIG_DIR_NAME)/$(MLX_DIR)/'
	@cd $(MLX_DIR); ./configure > /dev/null 2>&1
	@echo "$(GREEN)Compiled $(MLX_LIB_NAME) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"
	@for lib in $(LIBS_DIR)/*/; do \
		$(MAKE) -C $$lib clean > /dev/null; \
	done
	@# echo "$(RED)Removed libraries object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"
	@for lib in $(LIBS_DIR)/*/; do \
		$(MAKE) -C $$lib fclean > /dev/null; \
	done
	@# echo "$(RED)Removed .a libraries$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
