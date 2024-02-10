/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_htools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:11:32 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 10:06:14 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_direction(t_scene *scene)
{
	scene->mymlx->ray_angle = normalize_angle(scene->mymlx->ray_angle);
	scene->mymlx->RayFaceDown = scene->mymlx->ray_angle > 0
		&& scene->mymlx->ray_angle < M_PI;
	scene->mymlx->RayFaceUp = !scene->mymlx->RayFaceDown;
	scene->mymlx->RayFaceRight = scene->mymlx->ray_angle < 0.5 * M_PI
		|| scene->mymlx->ray_angle > 1.5 * M_PI;
	scene->mymlx->RayFaceLeft = !scene->mymlx->RayFaceRight;
}

void	init_horizontal(t_scene *scene)
{
	scene->mymlx->foundHorizWall = false;
	scene->mymlx->horiwallhitX = scene->mymlx->x;
	scene->mymlx->horiwallhitY = scene->mymlx->y;
}

void	incr_hsteps(t_scene *scene)
{
	scene->mymlx->Hyintercept = (int)(scene->mymlx->y / BLOCK) * BLOCK;
	if (scene->mymlx->RayFaceDown)
		scene->mymlx->Hyintercept += BLOCK;
	scene->mymlx->Hxintercept = scene->mymlx->x + (scene->mymlx->Hyintercept
			- scene->mymlx->y) / tan(scene->mymlx->ray_angle);
	scene->mymlx->ystep = BLOCK;
	if (scene->mymlx->RayFaceUp)
		scene->mymlx->ystep = -scene->mymlx->ystep;
	scene->mymlx->xstep = scene->mymlx->ystep / tan(scene->mymlx->ray_angle);
	scene->mymlx->nexthorztouchX = scene->mymlx->Hxintercept;
	scene->mymlx->nexthorztouchY = scene->mymlx->Hyintercept;
}

void	ishorizontal(t_scene *scene)
{
	init_direction(scene);
	init_horizontal(scene);
	incr_hsteps(scene);
	while (scene->mymlx->nexthorztouchX >= 0
		&& scene->mymlx->nexthorztouchX <= WIDTH
		&& scene->mymlx->nexthorztouchY >= 0
		&& scene->mymlx->nexthorztouchY <= HEIGHT)
	{
		scene->mymlx->xtocheck = scene->mymlx->nexthorztouchX;
		scene->mymlx->ytocheck = scene->mymlx->nexthorztouchY;
		if (scene->mymlx->RayFaceUp)
			scene->mymlx->ytocheck -= 1;
		if (map_has_wall(scene, scene->mymlx->xtocheck, scene->mymlx->ytocheck))
		{
			scene->mymlx->horiwallhitX = scene->mymlx->nexthorztouchX;
			scene->mymlx->horiwallhitY = scene->mymlx->nexthorztouchY;
			scene->mymlx->foundHorizWall = true;
			break ;
		}
		else
		{
			scene->mymlx->nexthorztouchX += scene->mymlx->xstep;
			scene->mymlx->nexthorztouchY += scene->mymlx->ystep;
		}
	}
}
