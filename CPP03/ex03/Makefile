NAME = DiamondTrap

FILES =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@$(COMPILER) $(FLAGS) $(FILES) -o $(NAME)
	@echo "Compilation successful"

clean:
	@echo "Cleaning"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
