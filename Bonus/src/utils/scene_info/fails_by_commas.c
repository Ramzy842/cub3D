/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fails_by_commas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:26:03 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:11:05 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	fails_by_commas(char *str)
{
	int	x;

	if (!str)
		return (0);
	if (str[0] == ',' || str[ft_strlen(str) - 1] == ',')
	{
		printf("\x1b[31mError\nElement fails by commas!\x1b[0m\n");
		free(str);
		return (1);
	}
	x = 0;
	while (str[x])
	{
		if (str[x] == ',')
		{
			if (str[x + 1] == ',')
			{
				printf("\x1b[31mError\nElement fails by commas!\x1b[0m\n");
				free(str);
				return (1);
			}
		}
		x++;
	}
	return (0);
}
