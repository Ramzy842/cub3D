/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:07:45 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 12:29:08 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_extension(char *path)
{
	int	path_length;

	path_length = ft_strlen(path);
	if (!(path[path_length - 1] == 'b' && path[path_length - 2] == 'u'
			&& path[path_length - 3] == 'c' && path[path_length - 4] == '.'))
	{
		printf("\x1b[31mError\n.cub extension is not found!\x1b[0m\n");
		return (0);
	}
	return (1);
}
