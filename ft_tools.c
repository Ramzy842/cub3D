/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:41:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 01:55:24 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

double	normalize_angle(double angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	distance_between_points(double x1, double y1, double x2, double y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	rad(float degree)
{
	return (degree * M_PI / 180);
}

double	get_short_distance(t_mymlx *mymlx)
{
	if (mymlx->horzHitDistance < mymlx->vertHitDistance)
		return (mymlx->horzHitDistance);
	else
		return (mymlx->vertHitDistance);
}

void	calculate_distance(t_mymlx *mymlx)
{
	printf("v[%f][%f] \n", mymlx->vertHitDistance,mymlx->horzHitDistance);
	if (fabs(mymlx->vertHitDistance) > fabs(mymlx->horzHitDistance))
	{
		mymlx->distance = mymlx->horzHitDistance;
		mymlx->wallHitX = mymlx->horiwallhitX;
		mymlx->wallHitY = mymlx->horiwallhitY;
			mymlx->wasHitVertical = false;
	}
	else
	{
		mymlx->distance = mymlx->vertHitDistance;
		mymlx->wallHitX = mymlx->VertwallhitX;
		mymlx->wallHitY = mymlx->VertwallhitY;
			mymlx->wasHitVertical = true;
	}
	drawline(mymlx);
}
