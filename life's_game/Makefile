NAME    = life_game

CC      = clang++
CFLAGS  = -Wall -Wextra -Werror -g3 $(ARGS)

INC_DIR = $(shell find includes -type d)
IFLAGS  = $(foreach dir, $(INC_DIR), -I$(dir))

SRC_DIR = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRCS = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

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
				@$(CC) $(CFLAGS) $(IFLAGS) `sdl2-config --cflags` -o $@ -c $<

$(NAME):		$(OBJ) $(INC_DIR) 
				@$(CC) $(CFLAGS) $(OBJ) `sdl2-config --libs` -lSDL2_ttf -lSDL2_image -o $(NAME)
				@rm -rf $(OBJ_DIR)
install:
				echo "user42" | sudo apt-get install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-dev

exec:			$(NAME)
				@./$(NAME)

re:				fclean all

clean:
				@rm -rf $(OBJ_DIR)

fclean:			clean
				@rm -f $(NAME)

.PHONY: all clean fclean re show exec install