/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_biggest_line_len.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:27:35 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 23:11:42 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	extract_biggest_line_len(char **map)
{
	int	x;
	int	line_len;
	int	biggest_len;

	if (!map)
		return (0);
	x = 0;
	line_len = 0;
	biggest_len = 0;
	while (map[x])
	{
		line_len = ft_strlen(map[x]);
		if (line_len >= biggest_len)
			biggest_len = line_len;
		x++;
	}
	return (biggest_len);
}
