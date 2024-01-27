/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:47:13 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 15:24:00 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	handle_empty_str_info(char *str)
{
	free(str);
	str = NULL;
}

void	assign_val_line(char *str, char **scene_info, int *count)
{
	scene_info[*count] = str;
	(*count)++;
}

char	**get_scene_info(char **scene, int *count)
{
	char	**scene_info;
	int		x;
	char	*str;

	x = 0;
	scene_info = malloc(sizeof(char *) * ((*count) + 1));
	if (!scene_info)
		return (NULL);
	scene_info[*count] = NULL;
	*count = 0;
	while (scene[x])
	{
		str = ft_strtrim(scene[x], " \t\n\r");
		if (!ft_strlen(str))
			handle_empty_str_info(str);
		else if (is_map_start(str) || are_walls(str))
			break ;
		else if (ft_strlen(str) > 0)
			assign_val_line(str, scene_info, count);
		x++;
	}
	return (scene_info);
}
