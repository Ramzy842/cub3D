/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:39:38 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:57:52 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	are_walls(char *str)
{
	int	x;

	x = 0;
	if (!ft_strlen(str) || !str)
		return (0);
	while (str[x])
	{
		if (str[x] != '1' && str[x] != ' ' && str[x] != '\t' && str[x] != '\n')
			return (0);
		x++;
	}
	free(str);
	str = NULL;
	return (1);
}
