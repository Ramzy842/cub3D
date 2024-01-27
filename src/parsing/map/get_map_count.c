/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:42:44 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 13:25:09 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_map_count(char **scene, int *map_start)
{
	int		x;
	int		var;

	if (!scene)
		return (0);
	x = 0;
	var = *map_start;
	while (scene[var])
	{
		(var)++;
		x++;
	}
	return (x);
}
