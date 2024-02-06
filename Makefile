# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 11:22:05 by rchahban          #+#    #+#              #
#    Updated: 2024/02/06 22:47:27 by mbouderr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Flags to pass to the compiler
CFLAGS =  #-g -fsanitize=address

# Includes (.h)
INCLUDES = -I./includes

# Source files for the cub3D executable
SRC = cub3D.c \
./texture.c\
	./src/utils/get_next_line/get_next_line_utils.c \
	./src/utils/get_next_line/get_next_line.c \
	./src/parsing/extension_checker.c ./src/utils/helpers/ft_2d_len.c \
	./src/parsing/read_scene.c ./src/utils/helpers/ft_strcmp.c \
	./src/utils/helpers/ft_atoi.c ./src/utils/helpers/ft_isalnum.c \
	./src/utils/helpers/ft_isdigit.c ./src/utils/helpers/ft_isprint.c \
	./src/utils/helpers/ft_itoa.c ./src/utils/helpers/ft_split.c \
	./src/utils/helpers/ft_strdup.c ./src/utils/helpers/custom_split.c \
	./src/utils/helpers/ft_strnstr.c  ./src/utils/helpers/join_2d_arr.c \
	./src/utils/helpers/ft_strtrim.c ./src/utils/helpers/ft_substr.c \
	./src/utils/map/begins_with_walls.c ./src/utils/map/ends_with_walls.c \
	./src/utils/helpers/strdup_2d_arr.c ./src/utils/helpers/free_2d_arr.c \
	./src/utils/map/are_walls.c src/utils/helpers/free_list.c ./src/utils/elements_list/add_element.c \
	./src/utils/elements_list/edit_node.c ./src/utils/elements_list/init_elements.c \
	./src/utils/elements_list/ids_found.c ./src/utils/map/is_player.c src/utils/map/is_map_start.c \
	./src/utils/scene_info/fails_by_commas.c ./src/utils/scene_info/are_numeric_values.c \
	./src/utils/scene_info/are_rgb_numbers.c ./src/utils/scene_info/is_rgb_number.c \
	./src/utils/elements_list/is_already_found.c ./src/utils/map/map_contains_player.c \
	./src/utils/helpers/ft_strtrim_end.c ./src/utils/map/get_player_props.c \
	./src/utils/map/path_finding/utils/in_visited.c ./src/utils/map/path_finding/utils/stack_ops.c \
	./src/utils/map/path_finding/path_checker.c ./src/utils/map/path_finding/utils/free_stack.c \
	./src/parsing/scene_info/handle_path_ids.c ./src/parsing/scene_info/vali_scene_info.c \
	./src/parsing/scene_info/handle_color_ids.c ./src/utils/map/path_finding/utils/create_stacks.c \
	./src/utils/map/path_finding/utils/free_nodes.c ./src/utils/map/path_finding/utils/free_stacks.c \
	./src/utils/map/path_finding/utils/search_void.c ./src/utils/map/path_finding/utils/get_next_moves.c \
	./src/parsing/map/extract_biggest_line_len.c ./printing.c ./src/parsing/map/map_contains_correct_possible_chars.c \
	./src/parsing/map/map_is_sorrounded_by_walls.c ./src/parsing/map/valid_map.c ./src/utils/helpers/custom_split2.c \
	./src/parsing/scene_info/handle_color_ids_utils.c ./src/parsing/map/rebuild_map.c \
	./src/parsing/map/get_scene_map.c ./src/parsing/map/get_map_count.c ./src/parsing/scene_info/get_scene_info.c \
	./src/parsing/scene_info/get_scene_info_count.c ./src/utils/helpers/ft_bzero.c ./src/utils/helpers/ft_memset.c \
# Object files for the cub3D executable, generated from the source files
OBJ = $(SRC:.c=.o)

# Define the name of the cub3D executable to be generated
NAME = cub3D

# Default target to be built
all: $(NAME)

# Generate the cub3D executable from the object files
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) ./MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"  -o $(NAME)

# Generate the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(patsubst %.c,%.o,$<)

# Clean target to remove generated files
clean:
	rm -f $(OBJ) map_utils.o map.o

# Fclean target to remove executable files and perform clean
fclean: clean
	rm -f $(NAME)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re