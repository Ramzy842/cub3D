/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:03:20 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/29 18:37:50 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include "../src/utils/get_next_line/get_next_line.h"

typedef struct Node
{
	int				x;
	int				y;
	struct Node		*next;
}	t_Node;

typedef struct Stack
{
	t_Node	*top;
}	t_Stack;

typedef struct s_element
{
	char				*id;
	int					found_status;
	char				*path;
	char				**colors;
	struct s_element	*next;
}	t_element;

typedef struct scene
{
	char		**scene_info;
	char		**temp_map;
	int			biggest_len;
	char		**map;
	t_element	*info_list;
	char		player_type;
	int			player_x;
	int			player_y;
	int			map_cols;
	int			map_rows;
	t_Stack		*s;
	t_Stack		*visited;
}	t_scene;

int		valid_extension(char *path);
char	**read_scene(char *map_path);
int		ft_2d_len(char **scene);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isdigit(int arg);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char *s1, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**custom_split(char *s);
char	*join_2d_arr(char **arr);
int		begins_with_wall(char *str);
int		ends_with_wall(char *str);
char	**strdup_2d_arr(char **ptr);
void	free_2d_arr(char **ptr);
int		are_walls(char *str);
void	free_list(t_element *list);
char	*ft_strtrim_end(char *s1, char *set);
void	get_player_props(t_scene *scene);

void	add_element(t_element **list, char *id, char *path, char **colors);
void	edit_node(t_element **list, char *id, char *path, char **colors);
void	init_elements(t_element **elements);
int		ids_found(t_element *list);
int		is_player(char c);
int		is_map_start(char *str);
int		fails_by_commas(char *str);
int		are_numeric_values(char **colors);
int		are_rgb_numbers(char **str);
int		is_rgb_number(int nbr);
int		is_already_found(t_element *list, char *i, char *str);
int		map_contains_player(char **map);
char	**custom_split2(char *s);
int		is_valid_color_id(char **colors);
char	**run_operations(char *str);
char	**rebuild_map(char **map, int biggest_len);
char	**get_scene_map(char **scene, int map_lines, int *map_start_pos);
int		get_map_count(char **scene, int *map_start);
int		in_visited(t_Stack	*visited, int a, int b);
void	push(t_Stack *stack, int x, int y);
t_Stack	*create_stack(void);
t_Node	*pop(t_Stack *stack);
int		is_empty(t_Stack *stack);
void	free_nodes(t_Node *head);
char	**get_scene_info(char **scene, int *count);
int		get_scene_info_count(char **scene, int *map_start_pos);
int		path_is_valid(t_scene *scene);
void	free_stack(t_Stack *stack);
void	free_stacks(t_scene *scene, t_Node *popped);
void	free_nodes(t_Node *head);
void	create_stacks(t_scene *scene);
void	print_2d_arr(char **colors);
int		handle_path_ids(t_element *list, char *id, char **str);
int		valid_scene_info(char **scene_info, t_element *list);
int		handle_color_ids(char **str, char *id, t_element *list, char *line);
int		handle_invalid_identifier(char *id, char **str);
void	search_void(t_Node *popped, int *void_found, t_scene *scene);
void	get_next_moves(t_Stack *s, int a, int b, t_scene *scene);
int		extract_biggest_line_len(char **map);
int		map_contains_correct_possible_chars(char **map);
int		map_is_sorrounded_by_walls(char **map);
int		valid_map(char **initial_map, t_scene *scene);
void	print_map(char **map);
void	display_list(t_element	*head);
#endif