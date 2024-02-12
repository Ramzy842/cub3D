/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:48:59 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:50:18 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_scene_info_count(char **scene, int *map_start_pos)
{
	int		count;
	int		x;
	char	*str;

	count = 0;
	x = 0;
	while (scene[x])
	{
		str = ft_strtrim(scene[x], " \t\n\r");
		if (!ft_strlen(str))
			free(str);
		else if (is_map_start(str) || are_walls(str))
		{
			*map_start_pos = x;
			break ;
		}
		else if (ft_strlen(str) > 0)
		{
			free(str);
			count++;
		}
		x++;
	}
	return (count);
}
