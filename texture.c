/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:52:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 23:41:10 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

mlx_texture_t	*text_so(t_scene *scene)
{
	scene->mymlx->so = mlx_load_png(scene->so_texture);
	printf("this is SO texture %s\n", scene->so_texture);
	if (scene->mymlx->so == NULL)
	{
		puts("No so texture\n");
		free(scene->mymlx);
		exit(0);
	}
	text_checker(scene->mymlx->so);
	return (scene->mymlx->so);
}

int	get_texture(t_mymlx *mymlx, mlx_texture_t *texture, int offset_x, int y)
{
	int	offset_y;
	int	index;

	offset_y = (y - 1 - (HEIGHT / 2) + (mymlx->s_3d.wallStripHeight / 2))
		* ((double)32 / mymlx->s_3d.wallStripHeight);
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
