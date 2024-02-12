/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:17:26 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 05:32:56 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	text_checker(mlx_texture_t *texture)
{
	if (!texture || texture->height != 32 || texture->width != 32)
	{
		printf("texture size is incorrect\n");
		exit(1);
	}
}

void	calcul_distance(t_scene *scene)
{
	scene->mymlx->ray_angle += scene->mymlx->fov_angle / scene->mymlx->num_rays;
	checkhori(scene);
	checkvert(scene);
}
