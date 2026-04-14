#name of the executable that will be created
NAME := clap

#name of c file with main function
MAIN := main.cpp
HDR_DIR = .

#source libs used in project
SRC_DIR :=	./src
SRC_ARC :=	$(SRC_DIR)/src.a

ALL_ARC := $(SRC_ARC)

#Vars
MAKEFLAGS += --no-print-directory

#commands and flags
COMPILER := c++
FLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

#other necessary links
LINKS := 

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

$(NAME): $(ALL_ARC) $(MAIN)
	@$(COMPILER) $(FLAGS) -o $@ -I$(HDR_DIR) $(MAIN) $(ALL_ARC)
	@echo "$(COLOUR_GREEN)Made main file$(COLOR_WHITE)"

$(ALL_ARC): FORCE
	@echo "$(COLOUR_BLUE)Updating archives of $@$(COLOR_WHITE)"
	-@cd $(dir $@ ) && (!(make -q) && make) || echo "$(COLOUR_YELLOW)	Already updated$(COLOR_WHITE)"

clean:
	@echo "$(COLOUR_YELLOW)Cleaning archives$(COLOR_WHITE)"
	@$(foreach dir,$(dir $(SRC_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))
	@$(foreach dir,$(dir $(HLP_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))


fclean: 
	@echo "$(COLOUR_YELLOW)Cleaning everything$(COLOR_WHITE)"
	@$(RM) $(NAME)
	@$(foreach dir,$(dir $(SRC_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))
	@$(foreach dir,$(dir $(HLP_ARC)), cd $(dir) && make fclean && echo$(NEWLINE)$(NEWLINE))

re: fclean all


.PHONY: all clean fclean re FORCE
