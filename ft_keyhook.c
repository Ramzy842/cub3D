/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:37:46 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 07:05:56 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	checkdir(t_mymlx *mymlx, double rotation_angle)
{
	double	tempy;
	double	tempx;

	tempy = mymlx->y + sin(rotation_angle) * mymlx->movespeed;
	tempx = mymlx->x + cos(rotation_angle) * mymlx->movespeed;
	mymlx->yisallowed = tempy;
	mymlx->xisallowed = tempx;
}

void	hook_awsd(t_scene *scene)
{
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(scene->mymlx->mlx);
		free_texture(scene);
	}
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_W))
		checkdir(scene->mymlx, scene->mymlx->rotation_angle);
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_A))
		checkdir(scene->mymlx, scene->mymlx->rotation_angle + rad(270));
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_D))
		checkdir(scene->mymlx, scene->mymlx->rotation_angle + rad(90));
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_S))
		checkdir(scene->mymlx, scene->mymlx->rotation_angle + rad(180));
}

int	is_move_allowed(t_scene *scene)
{
	return (scene->map[(int)scene->mymlx->yisallowed
			/ BLOCK][(int)scene->mymlx->xisallowed / BLOCK] != '1'
			&& scene->map[(int)scene->mymlx->y
			/ BLOCK][(int)scene->mymlx->xisallowed / BLOCK] != '1'
			&& scene->map[(int)scene->mymlx->yisallowed
		/ BLOCK][(int)scene->mymlx->x / BLOCK] != '1');
}

void	rightandleft(t_scene *scene)
{
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_LEFT))
	{
		scene->mymlx->rotation_angle -= 0.05;
		scene->mymlx->rotation_angle = 
			normalize_angle(scene->mymlx->rotation_angle);
	}
	if (mlx_is_key_down(scene->mymlx->mlx, MLX_KEY_RIGHT))
	{
		scene->mymlx->rotation_angle += 0.05;
		scene->mymlx->rotation_angle = 
			normalize_angle(scene->mymlx->rotation_angle);
	}
	if (is_move_allowed(scene))
	{
		scene->mymlx->x = scene->mymlx->xisallowed;
		scene->mymlx->y = scene->mymlx->yisallowed;
	}
}

void	ft_hook(void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	scene->mymlx->yisallowed = scene->mymlx->y;
	scene->mymlx->xisallowed = scene->mymlx->x;
	hook_awsd(scene);
	rightandleft(scene);
	print_grid(scene);
	cast_all_rays(scene);
	drawcircle(scene->mymlx);
}
