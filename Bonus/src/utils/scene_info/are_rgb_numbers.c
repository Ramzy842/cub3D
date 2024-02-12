/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_rgb_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:30:41 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 12:32:06 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	are_rgb_numbers(char **str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (!is_rgb_number(ft_atoi(str[x])))
			return (0);
		x++;
	}
	return (1);
}
