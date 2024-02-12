/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:28:38 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:59:49 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strdup(char *s1)
{
	char	*str;
	int		x;

	x = 0;
	if (!s1)
		return (NULL);
	while (s1[x])
		x++;
	str = malloc(x + 1);
	if (!str)
		return (str);
	x = 0;
	while (s1[x])
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
