/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 08:28:58 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/12 08:32:07 by rchahban         ###   ########.fr       */
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

int	all_tex_present(t_scene *scene)
{
	if (scene->mymlx->ea && scene->mymlx->so
		&& scene->mymlx->we && scene->mymlx->no)
		return (1);
	return (0);
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
