/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:04:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 10:09:42 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	check_wall(t_scene *scene)
{
	int	tile_x;
	int	tile_y;

	tile_x = scene->mymlx->newplayer_x / BLOCK;
	tile_y = scene->mymlx->newplayer_y / BLOCK;
	if (tile_x < 0 || tile_x >= scene->map_cols || tile_y < 0
		|| tile_y >= scene->map_rows)
	{
		exit(0);
	}
	if (scene->map[tile_y][tile_x] == '1' || scene->map[tile_y][tile_x] == 'V')
		return (1);
	else
		return (0);
}

int	map_has_wall(t_scene *scene, double x, double y)
{
	int		mapgridindex;
	int		mapgridindexy;
	char	mapcontent;

	if (x < 0 || x > WIDTH || y < 0 || y >= HEIGHT)
		return (true);
	mapgridindex = (int)floor(x / BLOCK);
	mapgridindexy = (int)floor(y / BLOCK);
	if (mapgridindex >= scene->map_cols)
		return (true);
	if (mapgridindexy >= scene->map_rows)
		return (true);
	mapcontent = scene->map[mapgridindexy][mapgridindex];
	return (mapcontent == '1');
}

void	rect(int tile_x, int tile_y, t_scene *scene, int value)
{
	int	end_x;
	int	end_y;
	int	current_y;

	end_x = tile_x + BLOCK;
	end_y = tile_y + BLOCK;
	while (tile_x < end_x)
	{
		current_y = tile_y;
		while (current_y < end_y)
		{
			if (value == 1)
				mlx_put_pixel(scene->mymlx->img, tile_x * 0.4, current_y * 0.4,
					0x0099FFFF);
			else
				mlx_put_pixel(scene->mymlx->img, tile_x * 0.4, current_y * 0.4,
					0x00FF00FF);
			current_y++;
		}
		tile_x++;
	}
}

void	print_grid(t_scene *scene)
{
	double	tile_x;
	double	tile_y;
	int		j;
	int		i;

	cloear(scene->mymlx->img, scene->mymlx);
	i = 0;
	while (i < scene->map_rows)
	{
		j = 0;
		while (j < scene->map_cols)
		{
			tile_x = j * BLOCK;
			tile_y = i * BLOCK;
			if (scene->map[i][j] == '1' || scene->map[i][j] == 'V')
				rect(tile_x, tile_y, scene, 1);
			if (scene->map[i][j] == '0' || scene->map[i][j] == 'N'
				|| scene->map[i][j] == 'S' || scene->map[i][j] == 'W'
				|| scene->map[i][j] == 'E')
				rect(tile_x, tile_y, scene, 0);
			j++;
		}
		i++;
	}
}

void	cloear(mlx_image_t *img, t_mymlx *mymlx)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < mymlx->num_col * BLOCK)
	{
		i = 0;
		while (i < mymlx->num_rows * BLOCK)
		{
			mlx_put_pixel(img, j, i, 0x000000FF);
			i++;
		}
		j++;
	}
}
