/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:18:42 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:56:33 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_map_start(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (!ft_isdigit(str[x]) && str[x] != ' ' && str[x] != '\t')
			return (0);
		x++;
	}
	free(str);
	str = NULL;
	return (1);
}
