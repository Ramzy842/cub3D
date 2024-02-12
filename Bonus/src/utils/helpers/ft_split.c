/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 12:49:54 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/09 08:01:46 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	x;

	count = 1;
	x = 0;
	while (str[x] != 0 && str[x] == c)
		x++;
	while (str[x] != '\0')
	{
		if (str[x] == c && str[x + 1] != c && str[x + 1] != '\0')
			count++;
		x++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	int		finish;
	int		start;
	char	**ptr;

	x = 0;
	y = 0;
	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	while (s[x] != '\0')
	{
		if (s[x] != c && (x == 0 || s[x - 1] == c))
			start = x;
		if (s[x] != c && (s[x + 1] == c || s[x + 1] == '\0'))
		{
			finish = x;
			ptr[y] = ft_substr(s, start, finish - start + 1);
			y++;
		}
		x++;
	}
	ptr[y] = NULL;
	return (ptr);
}
