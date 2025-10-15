NAME		=	fixed

SOURCES		=	main.cpp Fixed.cpp bsp.cpp Point.cpp

HEADERS		=	Fixed.hpp Point.hpp
OBJ_DIR		=	objects
OBJECTS		=	$(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98

# Colors for output
RED			=	\033[0;31m
MAGENTA		=	\033[1;31m
GREEN		=	\033[0;32m
LIME		=	\033[1;32m
YELLOW		=	\033[0;33m
BLUE		=	\033[0;34m
CYAN		=	\033[1;34m
RESET		=	\033[0m


all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(LIME)\n✓ $(NAME) compiled successfully!\n$(RESET)"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)Compiled: $<$ $(RESET)"

# Cleaning rules
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)Executable removed$(RESET)"

re: fclean all

# Phony targets
.PHONY: all clean fclean re