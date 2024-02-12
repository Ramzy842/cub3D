/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_vtools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:55:23 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 01:56:53 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_vertical(t_scene *scene)
{
	scene->mymlx->ray_angle = normalize_angle(scene->mymlx->ray_angle);
	scene->mymlx->foundVertWall = false;
	scene->mymlx->VertwallhitX = scene->mymlx->x;
	scene->mymlx->VertwallhitY = scene->mymlx->y;
}

void	find_intercept(t_scene *scene)
{
	scene->mymlx->Vxintercept = (int)(scene->mymlx->x / BLOCK) * BLOCK;
	if (scene->mymlx->RayFaceRight)
		scene->mymlx->Vxintercept += BLOCK;
	scene->mymlx->Vyintercept = scene->mymlx->y + (scene->mymlx->Vxintercept
			- scene->mymlx->x) * tan(scene->mymlx->ray_angle);
}

void	incr_vsteps(t_scene *scene)
{
	scene->mymlx->xstep = BLOCK;
	if (scene->mymlx->RayFaceLeft)
		scene->mymlx->xstep = -scene->mymlx->xstep;
	scene->mymlx->ystep = BLOCK * tan(scene->mymlx->ray_angle);
	if (scene->mymlx->RayFaceUp && scene->mymlx->ystep > 0)
		scene->mymlx->ystep = -scene->mymlx->ystep;
	else if (scene->mymlx->RayFaceDown && scene->mymlx->ystep < 0)
		scene->mymlx->ystep = -scene->mymlx->ystep;
}

void	vertical_functions(t_scene *scene)
{
	init_vertical(scene);
	find_intercept(scene);
	incr_vsteps(scene);
	scene->mymlx->xtocheck = scene->mymlx->nextVerttouchX;
	scene->mymlx->ytocheck = scene->mymlx->nextVerttouchY;
	scene->mymlx->nextVerttouchX = scene->mymlx->Vxintercept;
	scene->mymlx->nextVerttouchY = scene->mymlx->Vyintercept;
}

void	isvertical(t_scene *scene)
{
	vertical_functions(scene);
	while (scene->mymlx->nextVerttouchX >= 0
		&& scene->mymlx->nextVerttouchX <= WIDTH
		&& scene->mymlx->nextVerttouchY >= 0
		&& scene->mymlx->nextVerttouchY <= HEIGHT)
	{
		scene->mymlx->xtocheck = scene->mymlx->nextVerttouchX;
		scene->mymlx->ytocheck = scene->mymlx->nextVerttouchY;
		if (scene->mymlx->RayFaceLeft)
			scene->mymlx->xtocheck -= 1;
		if (map_has_wall(scene, scene->mymlx->xtocheck, scene->mymlx->ytocheck))
		{
			scene->mymlx->VertwallhitX = scene->mymlx->nextVerttouchX;
			scene->mymlx->VertwallhitY = scene->mymlx->nextVerttouchY;
			scene->mymlx->foundVertWall = true;
			break ;
		}
		else
		{
			scene->mymlx->nextVerttouchX += scene->mymlx->xstep;
			scene->mymlx->nextVerttouchY += scene->mymlx->ystep;
		}
	}
}
