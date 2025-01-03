# Compiler and Flags
CC      := cc
CFLAGS  = -Wall -Wextra -Werror $(INCLUDES)
MLX_FLAGS = -lXext -lX11

# Output Files
NAME    := so_long

# Directories
SRC_DIR := src
OBJ_DIR := obj
MLX_DIR := mlx

# Includes
INCLUDES := -I $(MLX_DIR)

# Files
MLX_ARCHIVE := mlx.tgz
MLX_FILES := libmlx.a
FILES   := $(notdir $(wildcard $(SRC_DIR)/*.c))

# Sources, Objects, Libraries
OBJ    := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
MLX_LIB := libmlx.a

# Colors for Output
GREEN   := \033[0;32m
RESET   := \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(MLX_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCLUDES) $(OBJ) $(MLX_LIB) -o $@
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

#Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

#Compile MLX
$(MLX_LIB): $(MLX_DIR)
	@cd $(MLX_DIR); ./configure > /dev/null 2>&1
	@cp $(MLX_DIR)/$(MLX_LIB) .

$(MLX_DIR):
	@tar xf $(MLX_ARCHIVE) --transform='s/^minilibx-linux/$(MLX_DIR)/'

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR) $(MLX_DIR) $(MLX_LIB)
	@echo "Removed object files."

# Clean up All Generated Files
fclean: clean
	@rm -rf $(NAME)
	@echo "Removed $(NAME)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re
