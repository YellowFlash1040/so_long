# Compiler, Flags and Tools
CC			:= cc
CFLAGS		:= -Wextra -Werror -Wall
RM			:= rm -f
MAKE		:= make -s

# Output Files
NAME		:= ft_printf.a

# Sources and Objects
SRC			:= ft_print_char_bonus.c \
				ft_printf.c \
				ft_printf_set_options.c \
				ft_printf_utils.c \
				ft_print_hex_bonus.c \
				ft_print_number_bonus.c \
				ft_print_number_left_aligned_bonus.c \
				ft_print_number_right_aligned_bonus.c \
				ft_print_numbers.c \
				ft_print_pointer_bonus.c \
				ft_print_string_and_pointer.c \
				ft_print_string_bonus.c \
				ft_print_unsigned_bonus.c
OBJ			:= $(SRC:.c=.o)

# External Libraries
LIBSTRING_PATH := ../string
LIBSTRING_NAME := string.a
LIBSTRING = $(LIBSTRING_PATH)/$(LIBSTRING_NAME)

# Colors for Output
GREEN		:= \033[0;32m
RED			:= \033[31m
RESET		:= \033[0m

# Default Target
all: $(NAME)

# Bonus Target
bonus: $(NAME)

# Build the Executable
$(NAME): $(OBJ) $(LIBSTRING)
	@cp $(LIBSTRING) $(NAME);
	@ar src $@ $(OBJ)
	@echo "$(GREEN)Compiled $@ successfully!$(RESET)"

#Compile Object Files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBSTRING):
	@cd $(LIBSTRING_PATH); $(MAKE); $(MAKE) clean > /dev/null

# Clean up Object Files
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)Removed object files$(RESET)"

# Clean up All Generated Files
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Removed $(NAME)$(RESET)"

# Rebuild the Project
re: fclean all

# Phony Targets
.PHONY: all clean fclean re bonus