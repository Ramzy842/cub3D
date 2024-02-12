/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:14:26 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/11 23:29:50 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	x;

	x = 0;
	while (x != len)
	{
		*(char *)(b + x) = (unsigned char)c;
		x++;
	}
	return (b);
}
