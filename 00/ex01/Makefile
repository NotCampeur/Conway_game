# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 08:17:15 by ldutriez          #+#    #+#              #
#    Updated: 2020/02/12 17:26:27 by ldutriez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phone_book

CC =		g++

SRC_DIR = 	$(shell find srcs -type d)
INC_DIR = 	$(shell find includes -type d)
OBJ_DIR = 	obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

#SRC = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.c), $(notdir $(file))))

SRC =	add_of_contact.cpp \
		\
		contact_creators.cpp contact_destructor.cpp contact_getters.cpp \
		contact_printers.cpp contact_printers_endl.cpp contact_setters.cpp

NORMAL_SRC = phone_book.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
NORMAL_OBJ = $(OBJ) $(addprefix $(OBJ_DIR)/, $(NORMAL_SRC:%.cpp=%.o))

#Compilation flag
CFLAGS = -Wall -Wextra -Werror #-O3 -fsanitize=address -g3

IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))

# Colors

_GREY=	$'\x1b[30m
_RED=	$'\x1b[31m
_GREEN=	$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=	$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=	$'\x1b[36m
_WHITE=	$'\x1b[37m

all:			$(NAME)

show:
				@echo "SRC :\n$(SRC)"
				@echo "OBJ :\n$(OBJ)"
				@echo "CFLAGS :\n$(CFLAGS)"
				@echo "IFLAGS :\n$(IFLAGS)"
				@echo "LIB_DIR:\n$(LIB_DIR)"
				@echo "LIB_INC :\n$(LIB_INC)"
				@echo "INC_DIR :\n$(INC_DIR)"

$(OBJ_DIR)/%.o : %.cpp
				@echo "Compiling $@ ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo "DONE"


$(NAME): 		$(INC_DIR) $(NORMAL_OBJ) Makefile
				@echo "-----\nCreating Executable $@ ... \c"
				@$(CC) $(CFLAGS) $(NORMAL_OBJ) -o $(NAME)
				@echo "DONE\n-----"

norme:
				norminette $(SRC_DIR)

re:				fclean all

clean:
				@echo "Deleting Objects Directory $(OBJ_DIR) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "DONE\n-----"

fclean:			clean
				@echo "Deleting Binary File $(NAME) ... \c"
				@rm -f $(NAME) $(BONUS_NAME)
				@echo "DONE\n-----"

.PHONY: all clean flcean re show norme