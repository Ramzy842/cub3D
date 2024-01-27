/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains_correct_possible_chars.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:31:48 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 10:23:26 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	map_contains_correct_possible_chars(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (!is_player(map[x][y])
				&& map[x][y] != '1'
				&& map[x][y] != '0'
				&& map[x][y] != ' ')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
