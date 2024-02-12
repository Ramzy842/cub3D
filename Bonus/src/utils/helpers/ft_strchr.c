/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:24:36 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 11:00:03 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	x;
	char	*str2;

	x = 0;
	str2 = (char *)str;
	while (x < ft_strlen(str2))
	{
		if (str2[x] == (char )c)
		{
			return (((char *) str2) + x);
		}
		x++;
	}
	if (str2[x] == (char )c)
	{
		return (((char *)str2) + x);
	}
	return (NULL);
}
