/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_numeric_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:27:28 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 22:01:07 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	are_numeric_values(char **colors)
{
	int	x;
	int	y;

	x = 0;
	while (colors[x])
	{
		y = 0;
		while (colors[x][y])
		{
			if (!ft_isdigit(colors[x][y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
