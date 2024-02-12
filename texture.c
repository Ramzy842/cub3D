/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:52:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 08:28:10 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

mlx_texture_t	*text_so(t_scene *scene)
{
	scene->mymlx->so = mlx_load_png(scene->so_texture);
	return (scene->mymlx->so);
}

int	get_texture(t_mymlx *mymlx, mlx_texture_t *texture, int offset_x, int y)
{
	int	offset_y;
	int	index;

	if (!texture || texture->height != 32 || texture->width != 32)
	{
		printf("\x1b[31mError\nInvalid texture size!\x1b[0m\n");
		exit (1);
	}
	offset_y = (y - 1 - (HEIGHT / 2) + (mymlx->s_3d.wallstripheight / 2))
		* ((double)32 / mymlx->s_3d.wallstripheight);
	index = (offset_y * 32 + offset_x) * 4;
	return (get_rgba(texture->pixels[index], texture->pixels[index + 1],
			texture->pixels[index + 2], texture->pixels[index + 3]));
}

void	free_texture(t_scene *scene)
{
	mlx_delete_texture(scene->mymlx->no);
	mlx_delete_texture(scene->mymlx->so);
	mlx_delete_texture(scene->mymlx->we);
	mlx_delete_texture(scene->mymlx->ea);
	free(scene->mymlx->mlx);
	exit(1);
}
