/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:57:30 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/04 17:47:31 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t			x;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	x = 0;
	while (str1[x] != '\0' || str2[x] != '\0')
	{
		if (str1[x] != str2[x])
			return (str1[x] - str2[x]);
		x++;
	}
	return (0);
}
