/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:37:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:38:35 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	copy_contents(char *s1, char *s2, int len)
{
	int	x;

	x = 0;
	while (s1[x])
	{
		if (s1[x] != '1' && s1[x] != '0'
			&& !is_player(s1[x])
			&& (s1[x] == ' '))
			s2[x] = 'V';
		else
			s2[x] = s1[x];
		x++;
	}
	while (x < len)
	{
		s2[x] = 'V';
		x++;
	}
}

char	**rebuild_map(char **map, int biggest_len)
{
	char	**new_map;
	int		count;
	int		map_len;
	char	*str;

	if (!map)
		return (NULL);
	count = 0;
	map_len = ft_2d_len(map);
	new_map = malloc(sizeof(char *) * (map_len + 1));
	if (!new_map)
		return (NULL);
	new_map[map_len] = NULL;
	while (map[count])
	{
		str = malloc(sizeof(char) * biggest_len + 1);
		if (!str)
			return (NULL);
		str[biggest_len] = '\0';
		copy_contents(map[count], str, biggest_len);
		new_map[count] = str;
		count++;
	}
	return (new_map);
}
