NAME = megaphone

CC = clang++

FLAG = -Wall -Wextra -Werror -fsanitize=address

SRCS = megaphone.cpp

all: $(NAME)

$(NAME):
	@echo Creating of executable $(NAME) 
	@$(CC) $(FLAG) $(SRCS) -o $(NAME)

re: fclean all

clean:

fclean: clean
	@echo Deleting executable
	@rm -rf megaphone

.PHONY: all re clean fclean
