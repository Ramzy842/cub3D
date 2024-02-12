/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:03:58 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:59:21 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strtrim_end(char *s1, char *set)
{
	char	*p;
	size_t	i;
	size_t	l;
	size_t	x;

	if (!set || !s1)
		return (NULL);
	x = 0;
	l = ft_strlen(s1);
	while (x < l && ft_strchr(set, s1[l - 1]) && l > 0)
		l--;
	p = (char *)malloc((l) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (x < l)
		p[i++] = s1[x++];
	p[i] = '\0';
	return (p);
}
