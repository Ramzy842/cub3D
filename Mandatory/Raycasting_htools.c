/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_htools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:11:32 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/13 15:29:28 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_direction(t_scene *scene)
{
	scene->mymlx->ray_angle = normalize_angle(scene->mymlx->ray_angle);
	scene->mymlx->rayfacedown = scene->mymlx->ray_angle > 0
		&& scene->mymlx->ray_angle < M_PI;
	scene->mymlx->rayfaceup = !scene->mymlx->rayfacedown;
	scene->mymlx->rayfaceright = scene->mymlx->ray_angle < 0.5 * M_PI
		|| scene->mymlx->ray_angle > 1.5 * M_PI;
	scene->mymlx->rayfaceleft = !scene->mymlx->rayfaceright;
}

void	init_horizontal(t_scene *scene)
{
	scene->mymlx->foundhorizwall = false;
	scene->mymlx->horiwallhitx = scene->mymlx->x;
	scene->mymlx->horiwallhity = scene->mymlx->y;
}

void	incr_hsteps(t_scene *scene)
{
	scene->mymlx->hyintercept = (int)(scene->mymlx->y / BLOCK) * BLOCK;
	if (scene->mymlx->rayfacedown)
		scene->mymlx->hyintercept += BLOCK;
	scene->mymlx->hxintercept = scene->mymlx->x + (scene->mymlx->hyintercept
			- scene->mymlx->y) / tan(scene->mymlx->ray_angle);
	scene->mymlx->ystep = BLOCK;
	if (scene->mymlx->rayfaceup)
		scene->mymlx->ystep = -scene->mymlx->ystep;
	scene->mymlx->xstep = BLOCK / tan(scene->mymlx->ray_angle);
	if ((scene->mymlx->rayfaceleft && scene->mymlx->xstep > 0)
		|| (scene->mymlx->rayfaceright && scene->mymlx->xstep < 0))
		scene->mymlx->xstep *= -1;
	scene->mymlx->nexthorztouchx = scene->mymlx->hxintercept;
	scene->mymlx->nexthorztouchy = scene->mymlx->hyintercept;
}

void	ishorizontal(t_scene *scene)
{
	init_direction(scene);
	init_horizontal(scene);
	incr_hsteps(scene);
	while (scene->mymlx->nexthorztouchx >= 0
		&& scene->mymlx->nexthorztouchx <= scene->map_cols * BLOCK
		&& scene->mymlx->nexthorztouchy >= 0
		&& scene->mymlx->nexthorztouchy <= scene->map_rows * BLOCK)
	{
		scene->mymlx->xtocheck = scene->mymlx->nexthorztouchx;
		scene->mymlx->ytocheck = scene->mymlx->nexthorztouchy;
		if (scene->mymlx->rayfaceup)
			scene->mymlx->ytocheck -= 1;
		if (map_has_wall(scene, scene->mymlx->xtocheck, scene->mymlx->ytocheck))
		{
			scene->mymlx->horiwallhitx = scene->mymlx->nexthorztouchx;
			scene->mymlx->horiwallhity = scene->mymlx->nexthorztouchy;
			scene->mymlx->foundhorizwall = true;
			break ;
		}
		else
		{
			scene->mymlx->nexthorztouchx += scene->mymlx->xstep;
			scene->mymlx->nexthorztouchy += scene->mymlx->ystep;
		}
	}
}
