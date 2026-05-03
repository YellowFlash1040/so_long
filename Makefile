#-----------------------COMPILATION------------------------------------------------------
# Compiler and Flags
CC						:= cc
CFLAGS					 = -Wall -Wextra -Werror $(INCLUDES) -g
MLX_FLAGS				:= -lXext -lX11
MAKE					:= make -s

# Include paths
INCLUDES				 = $(addprefix -I,$(SRC_DIRS)) \
							$(addprefix -I,$(LIB_DIRS)) \
							-Imlx

#-----------------------BINARIES---------------------------------------------------------
# Output Files
NAME					:= so_long

#-----------------------FOLDERS----------------------------------------------------------
# Directories
SRC_DIR					:= src
BUILD_DIR				:= build
OBJ_DIR					:= $(BUILD_DIR)/obj

SRC_DIRS				 = $(patsubst %/, %, $(sort $(dir $(HEADERS))))

MLX_DIR 				:= mlx
LIBS_DIR				:= libraries
LIB_FILE_DIR			:= $(LIBS_DIR)/file
LIB_FT_PRINTF_DIR		:= $(LIBS_DIR)/ft_printf
LIB_GET_NEXT_LINE_DIR	:= $(LIBS_DIR)/get_next_line
LIB_LIST_DIR			:= $(LIBS_DIR)/list
LIB_STRING_DIR			:= $(LIBS_DIR)/ft_string
LIB_CONVERTER_DIR		:= $(LIBS_DIR)/converter

LIB_DIRS				 = $(patsubst %/, %, $(sort $(dir $(LIBRARY_HEADERS))))

#Additional info
MLX_ORIG_DIR_NAME		:= minilibx-linux
MLX_LIB_NAME			:= libmlx.a

#-----------------------FILES------------------------------------------------------------
# Sources
C_FILES 				:= $(shell find $(SRC_DIR) -name '*.c')
HEADERS 				:= $(shell find $(SRC_DIR) -name '*.h')

# Libraries
LIBRARY_HEADERS			:= $(shell find $(LIBS_DIR) -name '*.h')

# Objects
OBJ     				:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_FILES))

# Archives
MLX_ARCHIVE				:= mlx.tgz

#-------------------------LIBRARIES------------------------------------------------------
# Libraries
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

#-----------------------COLORS-----------------------------------------------------------
# Colors for Output
GREEN					:= \033[0;32m
RED						:= \033[31m
BLUE					:= \033[0;34m
YELLOW					:= \033[0;33m
RESET					:= \033[0m

#-----------------------RULES------------------------------------------------------------
# Default Target
all: $(LIB_MLX) $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBRARIES)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBRARIES) $(MLX_FLAGS) -o $@
	@echo "\n$(GREEN)Compiled $@ successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile
	$(if $(COMPILE_MSG_SHOWN),,$(eval COMPILE_MSG_SHOWN := 1) \
	@echo "$(YELLOW)>> Compiling object files:$(RESET)")
	@printf "$(YELLOW)   %-38.38s\r" $(notdir $@)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile Libraries
%.a:
	@cd $(dir $@); $(MAKE) > /dev/null; $(MAKE) clean > /dev/null
	@echo "$(GREEN)Compiled $(notdir $@) successfully!$(RESET)"

# Compile MLX
$(LIB_MLX):
	@rm -rf $(MLX_DIR)
	@tar xf $(MLX_ARCHIVE) --transform='s/^$(MLX_ORIG_DIR_NAME)/$(MLX_DIR)/'
	# cd $(MLX_DIR); ./configure > /dev/null 2>&1
	cd $(MLX_DIR); ./configure
	@$(MAKE) -C $(MLX_DIR)
	echo "$(GREEN)Compiled $(MLX_LIB_NAME) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(BUILD_DIR)
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
