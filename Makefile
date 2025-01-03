# Compiler and Flags
CC        := cc
CFLAGS     = -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS := -lXext -lX11

# Output Files
NAME    := so_long

# Directories
SRC_DIR := src
OBJ_DIR := obj
MLX_DIR := mlx
MLX_ORIG_DIR_NAME := minilibx-linux

# Includes
INCLUDES := -I$(MLX_DIR)

# Files
MLX_ARCHIVE  := mlx.tgz
MLX_LIB_NAME := libmlx.a
FILES        := $(notdir $(wildcard $(SRC_DIR)/*.c))

# Objects, Libraries
OBJ     := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
MLX_LIB := $(addprefix $(MLX_DIR)/, $(MLX_LIB_NAME))

# Colors for Output
GREEN   := \033[0;32m
RED		:= \033[31m
RESET   := \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) -o $@
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

#Compile MLX
$(MLX_LIB):
	@rm -rf $(MLX_DIR)
	@tar xf $(MLX_ARCHIVE) --transform='s/^$(MLX_ORIG_DIR_NAME)/$(MLX_DIR)/'
	@cd $(MLX_DIR); ./configure > /dev/null 2>&1
	@echo "$(GREEN)Compiled $(MLX_LIB_NAME) successfully!$(RESET)"

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Removed object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
