/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:17:47 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:59:25 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*ft_strtrim(char *s1, char *set)
{
	char	*p;
	size_t	i;
	size_t	l;
	size_t	n;

	if (!set || !s1)
		return (NULL);
	n = 0;
	while (ft_strchr(set, s1[n]) && s1[n])
		n++;
	l = ft_strlen(s1);
	while (n < l && ft_strchr(set, s1[l - 1]) && l > 0)
		l--;
	p = (char *)malloc((l - n) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (n < l)
	{
		p[i++] = s1[n++];
	}
	p[i] = '\0';
	return (p);
}
