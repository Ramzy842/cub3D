/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:47:20 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 00:10:01 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_var(t_scene *scene)
{
	scene->mymlx->fov_angle = 60 * (M_PI / 180);
	scene->mymlx->movespeed = 15.0;
	scene->mymlx->rotation_speed = scene->mymlx->movespeed * (M_PI / 180);
	scene->mymlx->num_rays = WIDTH;
	playertype(scene);
	get_text(scene);
}

void	mlx_initiate(t_scene *scene)
{
	scene->mymlx->mlx = mlx_init(WIDTH, HEIGHT, "kalkabut", 0);
	scene->mymlx->img = mlx_new_image(scene->mymlx->mlx, scene->map_cols
			* BLOCK, scene->map_rows * BLOCK);
	scene->mymlx->img2 = mlx_new_image(scene->mymlx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img2, 0, 0);
	mlx_image_to_window(scene->mymlx->mlx, scene->mymlx->img, 0, 0);
	scene->mymlx->x = scene->x;
	scene->mymlx->y = scene->y;
}

void	get_scene_info_values(t_scene *scene)
{
	t_element	*current;

	current = scene->info_list;
	while (current)
	{
		if (!ft_strcmp(current->id, "EA"))
			scene->ea_texture = current->path;
		else if (!ft_strcmp(current->id, "WE"))
			scene->we_texture = current->path;
		else if (!ft_strcmp(current->id, "SO"))
			scene->so_texture = current->path;
		else if (!ft_strcmp(current->id, "NO"))
			scene->no_texture = current->path;
		else if (!ft_strcmp(current->id, "F"))
			scene->floor_colors = current->colors;
		else if (!ft_strcmp(current->id, "C"))
			scene->ceiling_colors = current->colors;
		current = current->next;
	}
}
