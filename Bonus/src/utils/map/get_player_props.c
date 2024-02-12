/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_props.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:50:55 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/11 23:29:11 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	get_player_props(t_scene *scene)
{
	int	x;
	int	y;

	if (!map_contains_player(scene->map))
		return ;
	x = 0;
	while (scene->map[x])
	{
		y = 0;
		while (scene->map[x][y])
		{
			if (is_player(scene->map[x][y]))
			{
				scene->player_x = x;
				scene->player_y = y;
				scene->x = y * 32 + 32 / 2;
				scene->y = x * 32 + 32 / 2;
				scene->player_type = scene->map[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}
