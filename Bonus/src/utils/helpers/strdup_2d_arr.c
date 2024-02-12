/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_2d_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:35:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 11:57:43 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	**strdup_2d_arr(char **ptr)
{
	int		x;
	char	**new_arr;

	x = 0;
	new_arr = malloc(sizeof(char *) * (ft_2d_len(ptr) + 1));
	while (ptr[x])
	{
		new_arr[x] = ft_strdup(ptr[x]);
		x++;
	}
	new_arr[x] = NULL;
	return (new_arr);
}
