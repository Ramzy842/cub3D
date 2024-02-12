/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:21:13 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/12 08:43:28 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	count_words(const char *str)
{
	int	count;
	int	x;

	count = 1;
	x = 0;
	while (str[x] != 0 
		&& (str[x] == ' '
			|| str[x] == '\t' || str[x] == '\n'
			|| str[x] == '\r'))
		x++;
	while (str[x] != '\0')
	{
		if ((str[x] == ' '
				|| str[x] == '\t' || str[x] == '\n'
				|| str[x] == '\r')
			&& (str[x + 1] != ' '
				&& str[x + 1] != '\t' && str[x + 1] != '\n'
				&& str[x + 1] != '\r')
			&& str[x + 1] != '\0')
			count++;
		x++;
	}
	return (count);
}

int	is_del(char *s, int x)
{
	if (s[x] == ' ' || s[x] == '\t'
		|| s[x] == '\n' || s[x] == '\r')
		return (1);
	return (0);
}

char	**custom_split(char *s)
{
	int		x;
	int		y;
	int		finish;
	int		start;
	char	**ptr;

	x = 0;
	y = 0;
	ptr = malloc((count_words(s) + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	while (s[x] != '\0')
	{
		if (!is_del(s, x) && (x == 0 || is_del(s, x - 1)))
			start = x;
		if (!is_del(s, x) && (s[x + 1] == '\0' || (is_del(s, x + 1))))
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
