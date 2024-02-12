/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 04:41:38 by mbouderr          #+#    #+#             */
/*   Updated: 2024/02/12 08:52:30 by rchahban         ###   ########.fr       */
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
	if (mymlx->horzhitdistance < mymlx->verthitdistance)
		return (mymlx->horzhitdistance);
	else
		return (mymlx->verthitdistance);
}

void	calculate_distance(t_mymlx *mymlx)
{
	if (fabs(mymlx->verthitdistance) > fabs(mymlx->horzhitdistance))
	{
		mymlx->distance = mymlx->horzhitdistance;
		mymlx->wallhitx = mymlx->horiwallhitx;
		mymlx->wallhity = mymlx->horiwallhity;
		mymlx->washitvertical = false;
	}
	else
	{
		mymlx->distance = mymlx->verthitdistance;
		mymlx->wallhitx = mymlx->vertwallhitx;
		mymlx->wallhity = mymlx->vertwallhity;
		mymlx->washitvertical = true;
	}
	drawline(mymlx);
}
