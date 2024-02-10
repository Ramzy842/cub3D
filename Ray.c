/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:52:42 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 19:34:52 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	drawline(t_mymlx *mymlx, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = (int)abs(x2 - x1);
	dy = (int)abs(y2 - y1);
	sx = (x1 < x2) ? 1 : -1;
	sy = (y1 < y2) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_put_pixel(mymlx->img, x1 * 0.4, y1 * 0.4, 0x455AED5);
		if (x1 == x2 && y1 == y2)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void	draw_player_view(t_mymlx *mymlx)
{
	int	lineEndX;
	int	lineEndY;

	lineEndX = mymlx->x + cos(mymlx->rotation_angle) * 30;
	lineEndY = mymlx->y + sin(mymlx->rotation_angle) * 30;
	drawline(mymlx, mymlx->x, mymlx->y, lineEndX, lineEndY);
}
void	calcul_distance(t_scene *scene)
{
	scene->mymlx->ray_angle += scene->mymlx->fov_angle / scene->mymlx->num_rays;
	if (scene->mymlx->foundHorizWall)
		scene->mymlx->horzHitDistance = distance_between_points(scene->mymlx->x,
				scene->mymlx->y, scene->mymlx->horiwallhitX,
				scene->mymlx->horiwallhitY);
	else
		scene->mymlx->horzHitDistance = 90000000000;
	if (scene->mymlx->foundVertWall)
		scene->mymlx->vertHitDistance = distance_between_points(scene->mymlx->x,
				scene->mymlx->y, scene->mymlx->VertwallhitX,
				scene->mymlx->VertwallhitY);
	else
		scene->mymlx->vertHitDistance = 90000000000;
}

void	cast_all_rays(t_scene *scene)
{
	int	colum_id;

	colum_id = 0;
	scene->mymlx->ray_angle = scene->mymlx->rotation_angle
		- (scene->mymlx->fov_angle / 2);
	while (colum_id < scene->mymlx->num_rays)
	{
		ishorizontal(scene);
		isvertical(scene);
		calcul_distance(scene);
		calculate_distance(scene->mymlx);
		three_drendring(scene, scene->mymlx, colum_id);
		colum_id++;
	}
}
