/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:50:59 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/13 17:07:45 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	circledrawing(t_mymlx *mymlx)
{
	int	radius;

	radius = 10;
	mlx_put_pixel(mymlx->img, (mymlx->x + radius) * 0.4, (mymlx->y - mymlx->cy)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x - radius) * 0.4, (mymlx->y - mymlx->cy)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x + mymlx->cy) * 0.4, (mymlx->y - radius)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x - mymlx->cy) * 0.4, (mymlx->y - radius)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x + radius) * 0.4, (mymlx->y + mymlx->cy)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x - radius) * 0.4, (mymlx->y + mymlx->cy)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x + mymlx->cy) * 0.4, (mymlx->y + radius)
		* 0.4, mymlx->circlecolor);
	mlx_put_pixel(mymlx->img, (mymlx->x - mymlx->cy) * 0.4, (mymlx->y + radius)
		* 0.4, mymlx->circlecolor);
}

void	drawcircle(t_mymlx *mymlx)
{
	int	radiuserr;
	int	radius;

	radius = 10;
	mymlx->cy = 0;
	radiuserr = 1 - radius;
	mymlx->circlecolor = 0x0099FFFF;
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
			if (value == 2)
				mlx_put_pixel(scene->mymlx->img, tile_x * 0.4, current_y * 0.4,
					0x1E453E99);
			else if (value == 1)
				mlx_put_pixel(scene->mymlx->img, tile_x * 0.4, current_y * 0.4,
					0x0F99FF97);
			else
				mlx_put_pixel(scene->mymlx->img, tile_x * 0.4, current_y * 0.4,
					0x182c25FF);
			current_y++;
		}
		tile_x++;
	}
}

void	print_grid(t_scene *scene)
{
	int		j;
	int		i;

	cloear(scene, scene->mymlx->img);
	i = 0;
	while (i < scene->map_rows)
	{
		j = 0;
		while (j < scene->map_cols)
		{
			if (scene->map[i][j] == '1')
				rect(j * BLOCK, i * BLOCK, scene, 1);
			else if (scene->map[i][j] == 'V')
				rect(j * BLOCK, i * BLOCK, scene, 2);
			else if (scene->map[i][j] == '0' || scene->map[i][j] == 'N'
				|| scene->map[i][j] == 'S' || scene->map[i][j] == 'W'
				|| scene->map[i][j] == 'E')
				rect(j * BLOCK, i * BLOCK, scene, 0);
			j++;
		}
		i++;
	}
}

void	cloear(t_scene *scene, mlx_image_t *img)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < scene->map_cols * BLOCK)
	{
		i = 0;
		while (i < scene->map_rows * BLOCK)
		{
			mlx_put_pixel(img, j * 0.4, i * 0.4, 0x000000FF);
			i++;
		}
		j++;
	}
}
