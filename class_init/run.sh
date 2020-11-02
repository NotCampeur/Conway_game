#! /bin/bash
clang++ -Wall -Wextra -Werror -fsanitize=address -g3 srcs/class_init.cpp srcs/class_init_data.cpp && ./a.out
rm -rf a.out