/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/13 18:10:49 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	check_wall(t_scene *scene)
{
	int	tile_x;
	int	tile_y;

	tile_x = scene->mymlx->newplayer_x / BLOCK;
	tile_y = scene->mymlx->newplayer_y / BLOCK;
	if (tile_x < 0 || tile_x >= scene->map_cols || tile_y < 0
		|| tile_y >= scene->map_rows)
	{
		exit(0);
	}
	if (scene->map[tile_y][tile_x] == '1' || scene->map[tile_y][tile_x] == 'V')
		return (1);
	else
		return (0);
}

int	map_has_wall(t_scene *scene, double x, double y)
{
	int		mapgridindex;
	int		mapgridindexy;
	char	mapcontent;

	if (x < 0 || x >= scene->map_cols * BLOCK || y < 0 || y >= scene->map_rows
		* BLOCK)
		return (0);
	mapgridindex = (int)floor(x / BLOCK);
	mapgridindexy = (int)floor(y / BLOCK);
	mapcontent = scene->map[mapgridindexy][mapgridindex];
	return (mapcontent == '1');
}

void	checkhori(t_scene *scene)
{
	if (scene->mymlx->foundhorizwall)
		scene->mymlx->horzhitdistance = distance_between_points(scene->mymlx->x,
				scene->mymlx->y, scene->mymlx->horiwallhitx,
				scene->mymlx->horiwallhity);
	else
		scene->mymlx->horzhitdistance = __INT_MAX__;
}

void	checkvert(t_scene *scene)
{
	if (scene->mymlx->foundvertwall)
		scene->mymlx->verthitdistance = distance_between_points(scene->mymlx->x,
				scene->mymlx->y, scene->mymlx->vertwallhitx,
				scene->mymlx->vertwallhity);
	else
		scene->mymlx->verthitdistance = __INT_MAX__;
}

void	cast_all_rays(t_scene *scene)
{
	int	colum_id;

	colum_id = 0;
	scene->mymlx->ray_angle = scene->mymlx->rotation_angle
		- (scene->mymlx->fov_angle / 2);
	while (colum_id < scene->mymlx->num_rays)
	{
		scene->mymlx->ray_angle = normalize_angle(scene->mymlx->ray_angle);
		ishorizontal(scene);
		isvertical(scene);
		calcul_distance(scene);
		calculate_distance(scene->mymlx);
		three_drendring(scene, scene->mymlx, colum_id);
		colum_id++;
	}
}
