/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtextures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:28:37 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 08:34:04 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	all_tex_size_valid(t_scene *scene)
{
	if (scene->mymlx->ea->height != 32 || scene->mymlx->ea->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->no->height != 32 || scene->mymlx->no->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->we->height != 32 || scene->mymlx->we->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	if (scene->mymlx->so->height != 32 || scene->mymlx->so->width != 32)
	{
		printf("\x1b[31mInvalid texture size!\x1b[0m\n");
		return (0);
	}
	return (1);
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
		exit (1);
	}
}
