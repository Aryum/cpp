#name of the library
NAME := src.a

#required files
SRC :=	ScavTrap.cpp	\
		FragTrap.cpp	\
		ClapTrap.cpp	\


OBJ :=	$(SRC:.cpp=.o)

HDR_DIR := .

#commands and flags
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
AR := ar -rcs
RM := rm -f

#variables to make things pretty
blank :=
define NEWLINE

$(blank)
endef

COLOUR_GREEN := \033[1;32m
COLOUR_RED := \033[1;31m
COLOUR_YELLOW := \033[1;33m
COLOUR_BLUE := \033[1;34m
COLOR_WHITE := \033[0m

all: $(NAME)

$(NAME): $(SRC)
	@$(foreach cfile,$(SRC), $(COMPILER) $(FLAGS) -o $(cfile:.cpp=.o) -c $(cfile) -I$(HDR_DIR) $(NEWLINE))
	@$(AR) $@ $(SRC:.cpp=.o)
	@echo "$(COLOUR_GREEN)	Making $(NAME)$(COLOUR_WHITE)"
	@$(RM) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo "$(COLOUR_YELLOW)	Cleaning objects of $(NAME)$(COLOUR_WHITE)"

fclean:
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@echo "$(COLOUR_RED)	Cleaning $(NAME)$(COLOUR_WHITE)"

re: fclean all

.PHONY: all clean fclean re