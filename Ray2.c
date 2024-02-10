/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:50:59 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 22:07:35 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	circledrawing(t_mymlx *mymlx)
{
	int	radius;

	radius = 10;
	mlx_put_pixel(mymlx->img, (mymlx->x + radius) * 0.4, (mymlx->y - mymlx->cy)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x - radius) * 0.4, (mymlx->y - mymlx->cy)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x + mymlx->cy) * 0.4, (mymlx->y - radius)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x - mymlx->cy) * 0.4, (mymlx->y - radius)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x + radius) * 0.4, (mymlx->y + mymlx->cy)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x - radius) * 0.4, (mymlx->y + mymlx->cy)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x + mymlx->cy) * 0.4, (mymlx->y + radius)
		* 0.4, mymlx->circleColor);
	mlx_put_pixel(mymlx->img, (mymlx->x - mymlx->cy) * 0.4, (mymlx->y + radius)
		* 0.4, mymlx->circleColor);
}

void	drawcircle(t_mymlx *mymlx)
{
	int	radiuserr;
	int	radius;

	radius = 10;
	mymlx->cy = 0;
	radiuserr = 1 - radius;
	while (radius >= mymlx->cy)
	{
		circledrawing(mymlx);
		mymlx->cy++;
		if (radiuserr < 0)
			radiuserr += 2 * mymlx->cy + 1;
		else
		{
			radius--;
			radiuserr += 2 * (mymlx->cy - radius + 1);
		}
	}
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
			if (scene->map[i][j] == '1')
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
