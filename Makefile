NAME    = life_game

CC      = clang++
CFLAGS  = -Wall -Wextra -Werror -g3

DEBUG =
ifdef DEBUG
    CFLAGS += -fsanitize=address
endif

INC_DIR = $(shell find includes -type d)
IFLAGS  = $(foreach dir, $(INC_DIR), -I$(dir))

SRC_DIR = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRCS =	main.cpp \
		event_center.cpp mouse_management.cpp key_management.cpp \
		system.cpp load.cpp update.cpp apply_rules.cpp \
		SDL_PointInit.cpp SDL_ColorInit.cpp SDL_RectInit.cpp \
		input_editor.cpp message_box.cpp SDL_MessageBox.cpp \
		render.cpp draw_color.cpp draw_grid.cpp draw_boxes.cpp draw_rect.cpp \
		text_management.cpp texture_management.cpp grid_management.cpp

OBJ_DIR = obj
OBJ     = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

SDL_FILE = /usr/include/SDL2/SDL.h

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all: 			$(NAME)

show:
				@echo "SRCS :\n$(SRCS)"
				@echo "OBJ :\n$(OBJ)"
				@echo "CFLAGS :\n$(CFLAGS)"
				@echo "IFLAGS :\n$(IFLAGS)"
				@echo "INC_DIR :\n$(INC_DIR)"

$(OBJ_DIR)/%.o : %.cpp
				@echo "Compiling $(_PURPLE)sources $(_YELLOW)$@$(_WHITE) ... \c"
				@mkdir -p $(OBJ_DIR)
				@$(CC) $(CFLAGS) $(IFLAGS) `sdl2-config --cflags` -o $@ -c $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME):		$(SDL_FILE) $(OBJ) $(INC_DIR)
				@echo "-----\nCreating $(_BLUE)Executable $(_YELLOW)$@$(_WHITE) ... \c"
				@$(CC) $(CFLAGS) $(OBJ) `sdl2-config --libs` -lSDL2_ttf -lSDL2_image -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(SDL_FILE):
				@echo -n "-----\nInstalling $(_YELLOW)SDL2$(_WHITE) ... "
				@echo "ldutriez" | sudo -S echo "installing SDL"
				@yes | sudo apt-get install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-dev
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

install :
			@echo -n "-----\nInstalling $(_YELLOW)SDL2$(_WHITE) ... "
			@echo "ldutriez" | sudo -S echo "installing SDL"
			@yes | sudo apt-get install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-dev libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-dev
			@echo "$(_GREEN)DONE$(_WHITE)\n-----"

print-%: ; @echo $*=$($*)

exec:			$(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME)
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

re:				fclean all

clean:
				@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo "Deleting Binaries Files $(_YELLOW)$(NAME)$(_WHITE) ... \c"
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all clean fclean re show exec install