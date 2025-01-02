# Compiler and Flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Output Files
NAME    := src/so_long

# Directories
SRC_DIR := src
OBJ_DIR := obj
# BONUS_DIR := bonus
# BONUS_OBJ_DIR := bonus_obj

# Files
FILES   := $(notdir $(wildcard $(SRC_DIR)/*.c))

# Sources and Objects
SRCS    := $(addprefix $(SRC_DIR)/, $(FILES))
OBJS    := $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
# BONUS_SRCS := $(addprefix $(BONUS_DIR)/, $(BONUS_FILES)) $(addprefix $(SRC_DIR)/, $(SHARED_FILES))
# BONUS_OBJS := $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o)) $(addprefix $(BONUS_OBJ_DIR)/, $(SHARED_FILES:.c=.o))

# Colors for Output
GREEN   := \033[0;32m
RESET   := \033[0m

# Default Target
all: $(NAME)

# Build the Executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "$(GREEN)Compiled $(NAME) successfully!$(RESET)"

# bonus: $(BONUS_NAME)

# $(BONUS_NAME): $(BONUS_OBJS)
# 	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $@
# 	@echo "$(GREEN)Compiled $(BONUS_NAME) successfully!$(RESET)"

# Compile Object Files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# $(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
# 	@mkdir -p $(BONUS_OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(BONUS_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
# 	@mkdir -p $(BONUS_OBJ_DIR)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up Object Files
clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@echo "Removed object files."

# Clean up All Generated Files
fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "Removed $(NAME) and $(BONUS_NAME)."

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re #bonus
