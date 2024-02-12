/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_2d_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:18:50 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 11:57:08 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*join_2d_arr(char **arr)
{
	int		x;
	char	*str; 

	if (!arr)
		return (NULL);
	x = 0;
	str = NULL;
	while (arr[x])
	{
		str = ft_strjoin(str, arr[x]);
		x++;
	}
	return (str);
}
