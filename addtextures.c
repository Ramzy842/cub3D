/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:28:37 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 23:36:49 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	get_text(t_scene *scene)
{
	scene->mymlx->ea = text_ea(scene);
	scene->mymlx->no = text_no(scene);
	scene->mymlx->so = text_so(scene);
	scene->mymlx->we = text_we(scene);
}

mlx_texture_t	*text_no(t_scene *scene)
{
	scene->mymlx->no = mlx_load_png(scene->no_texture);
	if (scene->mymlx->no == NULL)
	{
		puts("No no texture\n");
		free(scene->mymlx);
		exit(0);
	}
	text_checker(scene->mymlx->no);
	return (scene->mymlx->no);
}

mlx_texture_t	*text_ea(t_scene *scene)
{
	scene->mymlx->ea = mlx_load_png(scene->ea_texture);
	if (scene->mymlx->ea == NULL)
	{
		puts("No  ea texture\n");
		free(scene->mymlx);
		exit(0);
	}
	text_checker(scene->mymlx->ea);
	return (scene->mymlx->ea);
}

mlx_texture_t	*text_we(t_scene *scene)
{
	scene->mymlx->we = mlx_load_png(scene->we_texture);
	if (scene->mymlx->we == NULL)
	{
		free(scene->mymlx);
		exit(0);
	}
	text_checker(scene->mymlx->we);
	return (scene->mymlx->we);
}
