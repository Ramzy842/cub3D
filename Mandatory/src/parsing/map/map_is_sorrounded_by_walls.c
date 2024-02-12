/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_sorrounded_by_walls.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:32:02 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 10:25:45 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	inside_map_is_sorrounded_by_walls(char **map)
{
	int		x;
	char	*str;

	if (!map)
		return (0);
	x = 1;
	str = NULL;
	while (map[x] && x != (ft_2d_len(map) - 1))
	{
		str = ft_strtrim(map[x], " V\t\n\r");
		if (!begins_with_wall(str) || !ends_with_wall(str))
		{
			free(str);
			return (0);
		}
		if (str)
			free(str);
		x++;
	}
	return (1);
}

int	are_custom_walls(char *str)
{
	int	x;

	x = 0;
	if (!ft_strlen(str) || !str)
		return (0);
	while (str[x])
	{
		if (str[x] != '1' && str[x] != ' '
			&& str[x] != '\t' && str[x] != '\n'
			&& str[x] != 'V')
			return (0);
		x++;
	}
	return (1);
}

int	map_is_sorrounded_by_walls(char **map)
{
	char	*first_line;
	char	*last_line;

	if (!map)
		return (0);
	first_line = ft_strtrim(map[0], " V\t\n\r");
	last_line = ft_strtrim(map[ft_2d_len(map) - 1], " V\t\n\r");
	if (!are_custom_walls(first_line) || ! are_custom_walls(last_line))
	{
		free(first_line);
		free(last_line);
		return (0);
	}
	else if (!inside_map_is_sorrounded_by_walls(map))
	{
		free(first_line);
		free(last_line);
		return (0);
	}
	free(first_line);
	free(last_line);
	return (1);
}
