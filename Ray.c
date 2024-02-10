/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 09:52:42 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/10 22:15:51 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_values(t_mymlx *mymlx)
{
	mymlx->xx1 = mymlx->x;
	mymlx->yy1 = mymlx->y;
	mymlx->xx2 = mymlx->wallHitX;
	mymlx->yy2 = mymlx->wallHitY;
	mymlx->dx = (int)abs(mymlx->xx2 - mymlx->xx1);
	mymlx->dy = (int)abs(mymlx->yy2 - mymlx->yy1);
}

void	dda1(t_mymlx *mymlx)
{
	mymlx->err -= mymlx->dy;
	mymlx->xx1 += mymlx->sx;
}

void	dda2(t_mymlx *mymlx)
{
	mymlx->err += mymlx->dx;
	mymlx->yy1 += mymlx->sy;
}

void	drawline(t_mymlx *mymlx)
{
	init_values(mymlx);
	if (mymlx->xx1 < mymlx->xx2)
		mymlx->sx = 1;
	else
		mymlx->sx = -1;
	if (mymlx->yy1 < mymlx->yy2)
		mymlx->sy = 1;
	else
		mymlx->sy = -1;
	mymlx->err = mymlx->dx - mymlx->dy;
	while (1)
	{
		mlx_put_pixel(mymlx->img, mymlx->xx1 * 0.4, mymlx->yy1 * 0.4, 0xeeeee);
		if (mymlx->xx1 == mymlx->xx2 && mymlx->yy1 == mymlx->yy2)
			break ;
		mymlx->e2 = 2 * mymlx->err;
		if (mymlx->e2 > -mymlx->dy)
			dda1(mymlx);
		if (mymlx->e2 < mymlx->dx)
			dda2(mymlx);
	}
}
