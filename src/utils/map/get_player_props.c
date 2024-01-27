/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_props.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:50:55 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 14:06:01 by rchahban         ###   ########.fr       */
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
				scene->player_type = scene->map[x][y];
				return ;
			}
			y++;
		}
		x++;
	}
}
