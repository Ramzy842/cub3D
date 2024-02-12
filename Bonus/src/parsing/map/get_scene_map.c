/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:41:42 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/12 08:45:05 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_empty_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
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

int	is_map_end(char **scene, int increment)
{
	char	*tmp;

	while (scene[increment])
	{
		tmp = ft_strtrim(scene[increment], " \t\n\r");
		if (ft_strlen(tmp))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		tmp = NULL;
		increment++;
	}
	return (1);
}

char	**res(char *str, char **map, int count)
{
	free(str);
	map[count] = NULL;
	return (map);
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
			if (is_map_end(scene, *map_start_pos + 1))
				return (res(str, map, count));
			else if (!handle_empty_str(str))
				return (NULL);
		}
		else
			assign_value_to_line(scene[*map_start_pos], str, map, &count);
		(*map_start_pos)++;
	}
	map[count] = NULL;
	if (scene)
		free_2d_arr(scene);
	return (map);
}
