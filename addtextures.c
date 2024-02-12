/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:28:37 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 07:29:14 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	free_tex(t_scene *scene)
{
	if (scene->mymlx->ea)
		mlx_delete_texture(scene->mymlx->ea);
	if (scene->mymlx->no)
		mlx_delete_texture(scene->mymlx->no);
	if (scene->mymlx->so)
		mlx_delete_texture(scene->mymlx->so);
	if (scene->mymlx->we)
		mlx_delete_texture(scene->mymlx->we);
}

int	all_tex_size_valid(t_scene *scene)
{
	if (scene->mymlx->ea->height != 32 ||  scene->mymlx->ea->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->no->height != 32 ||  scene->mymlx->no->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->we->height != 32 ||  scene->mymlx->we->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->so->height != 32 ||  scene->mymlx->so->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	return (1);
}

int	all_tex_present(t_scene *scene)
{
	if (scene->mymlx->ea && scene->mymlx->so
		&& scene->mymlx->we && scene->mymlx->no)
			return (1);
	return (0);
}

void	get_text(t_scene *scene)
{
	scene->mymlx->ea = text_ea(scene);
	scene->mymlx->no = text_no(scene);
	scene->mymlx->so = text_so(scene);
	scene->mymlx->we = text_we(scene);
	if (!all_tex_present(scene))
	{
		printf("\x1b[31mError\nInvalid texture!\x1b[0m\n");
		free_tex(scene);
		exit(1);
	}
	else if (!all_tex_size_valid(scene))
	{
		free_tex(scene);
		while(1);
		exit(1);
	}
}

mlx_texture_t	*text_no(t_scene *scene)
{
	scene->mymlx->no = mlx_load_png(scene->no_texture);
	return (scene->mymlx->no);
}

mlx_texture_t	*text_ea(t_scene *scene)
{
	scene->mymlx->ea = mlx_load_png(scene->ea_texture);
	return (scene->mymlx->ea);
}

mlx_texture_t	*text_we(t_scene *scene)
{
	scene->mymlx->we = mlx_load_png(scene->we_texture);
	return (scene->mymlx->we);
}
