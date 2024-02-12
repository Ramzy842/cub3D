/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Raycasting_vtools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:55:23 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 08:52:30 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_vertical(t_scene *scene)
{
	scene->mymlx->foundvertwall = 0;
	scene->mymlx->vertwallhitx = scene->mymlx->x;
	scene->mymlx->vertwallhity = scene->mymlx->y;
}

void	find_intercept(t_scene *scene)
{
	scene->mymlx->vxintercept = (int)(scene->mymlx->x / BLOCK) * BLOCK;
	if (scene->mymlx->rayfaceright)
		scene->mymlx->vxintercept += BLOCK;
	scene->mymlx->vyintercept = scene->mymlx->y + (scene->mymlx->vxintercept
			- scene->mymlx->x) * tan(scene->mymlx->ray_angle);
}

void	incr_vsteps(t_scene *scene)
{
	scene->mymlx->xstep = BLOCK;
	if (scene->mymlx->rayfaceleft)
		scene->mymlx->xstep = -scene->mymlx->xstep;
	scene->mymlx->ystep = BLOCK * tan(scene->mymlx->ray_angle);
	if ((scene->mymlx->rayfaceup && scene->mymlx->ystep > 0)
		|| (scene->mymlx->rayfacedown && scene->mymlx->ystep < 0))
		scene->mymlx->ystep *= -1;
}

void	vertical_functions(t_scene *scene)
{
	init_vertical(scene);
	find_intercept(scene);
	incr_vsteps(scene);
	scene->mymlx->xtocheck = scene->mymlx->nextverttouchx;
	scene->mymlx->ytocheck = scene->mymlx->nextverttouchy;
	scene->mymlx->nextverttouchx = scene->mymlx->vxintercept;
	scene->mymlx->nextverttouchy = scene->mymlx->vyintercept;
}

void	isvertical(t_scene *scene)
{
	vertical_functions(scene);
	while (scene->mymlx->nextverttouchx >= 0
		&& scene->mymlx->nextverttouchx <= scene->map_cols * BLOCK
		&& scene->mymlx->nextverttouchy >= 0
		&& scene->mymlx->nextverttouchy <= scene->map_rows * BLOCK)
	{
		scene->mymlx->xtocheck = scene->mymlx->nextverttouchx;
		scene->mymlx->ytocheck = scene->mymlx->nextverttouchy;
		if (scene->mymlx->rayfaceleft)
			scene->mymlx->xtocheck -= 1;
		if (map_has_wall(scene, scene->mymlx->xtocheck, scene->mymlx->ytocheck))
		{
			scene->mymlx->vertwallhitx = scene->mymlx->nextverttouchx;
			scene->mymlx->vertwallhity = scene->mymlx->nextverttouchy;
			scene->mymlx->foundvertwall = true;
			break ;
		}
		else
		{
			scene->mymlx->nextverttouchx += scene->mymlx->xstep;
			scene->mymlx->nextverttouchy += scene->mymlx->ystep;
		}
	}
}
