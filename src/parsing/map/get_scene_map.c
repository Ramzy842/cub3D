/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:41:42 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 13:43:25 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_empty_str(char *str, char **map)
{
	if (str)
	{
		free(str);
		str = NULL;
		free_2d_arr(map);
		return (0);
	}
	return (1);
}

void	assign_value_to_line(char *line, char *str, char **map, int *count)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	str = ft_strtrim(line, "\n");
	map[*count] = str;
	(*count)++;
}

char	**get_scene_map(char **scene, int map_lines, int *map_start_pos)
{
	char	**map;
	int		count;
	char	*str;

	count = 0;
	map = malloc(sizeof(char *) * (map_lines + 1));
	map[map_lines] = NULL;
	while (scene[*map_start_pos])
	{
		str = ft_strtrim(scene[*map_start_pos], " \t\n\r");
		if (!ft_strlen(str))
		{
			if (!handle_empty_str(str, map))
				return (NULL);
		}
		else
			assign_value_to_line(scene[*map_start_pos], str, map, &count);
		(*map_start_pos)++;
	}
	if (scene)
		free_2d_arr(scene);
	return (map);
}
