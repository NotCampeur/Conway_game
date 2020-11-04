NAME    = replace

CC      = clang++
CFLAGS  = -Wall -Wextra -Werror -g3 $(ARGS)

INC_DIR = $(shell find includes -type d)
IFLAGS  = $(foreach dir, $(INC_DIR), -I$(dir))

vpath %.cpp srcs

SRC_DIR = $(shell find srcs -type d)
SRCS    = replacer.cpp system_data.cpp

OBJ_DIR = obj
OBJ     = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

all: 			$(NAME)

show:
				@echo "SRCS :\n$(SRCS)"
				@echo "OBJ :\n$(OBJ)"
				@echo "CFLAGS :\n$(CFLAGS)"
				@echo "IFLAGS :\n$(IFLAGS)"
				@echo "INC_DIR :\n$(INC_DIR)"

$(OBJ_DIR)/%.o : %.cpp
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME):		$(OBJ) $(INC_DIR) 
				@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@rm -rf $(OBJ_DIR)

re:				fclean all

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -f $(NAME)

.PHONY: all clean fclean re show