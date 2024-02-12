/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:25:46 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 10:51:06 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	playertype(t_scene *scene)
{
	if (scene->player_type == 'N')
		scene->mymlx->rotation_angle = 3 * M_PI / 2;
	else if (scene->player_type == 'S')
		scene->mymlx->rotation_angle = M_PI / 2;
	else if (scene->player_type == 'E')
		scene->mymlx->rotation_angle = 0;
	else if (scene->player_type == 'W')
		scene->mymlx->rotation_angle = M_PI;
}

void	getcolors(t_scene *scene)
{
	scene->mymlx->cred = ft_atoi(scene->ceiling_colors[0]);
	scene->mymlx->cgreen = ft_atoi(scene->ceiling_colors[1]);
	scene->mymlx->cblue = ft_atoi(scene->ceiling_colors[2]);
	scene->mymlx->fred = ft_atoi(scene->floor_colors[0]);
	scene->mymlx->fgreen = ft_atoi(scene->floor_colors[1]);
	scene->mymlx->fblue = ft_atoi(scene->floor_colors[2]);
}
