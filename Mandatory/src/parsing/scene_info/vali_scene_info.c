/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vali_scene_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:50:17 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 15:33:25 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	handle_two_elements_state(char **str)
{
	printf("\x1b[31mError\nNot a complete element in line!\x1b[0m\n");
	free_2d_arr(str);
	return (0);
}

int	is_path_id(char *id)
{
	if (!ft_strcmp(id, "NO") || !ft_strcmp(id, "SO")
		|| !ft_strcmp(id, "WE") || !ft_strcmp(id, "EA"))
		return (1);
	return (0);
}

int	is_color_id(char *id)
{
	if (!ft_strcmp(id, "F") || !ft_strcmp(id, "C"))
		return (1);
	return (0);
}

int	valid_scene_info(char **scene_info, t_element *list)
{
	int		x;
	char	**str;
	char	*id;

	x = -1;
	while (scene_info[++x])
	{
		str = custom_split(scene_info[x]);
		if (ft_2d_len(str) < 2 || !list)
			return (handle_two_elements_state(str));
		id = ft_strdup(str[0]);
		if (is_path_id(id))
		{
			if (!handle_path_ids(list, id, str))
				return (0);
		}
		else if (is_color_id(id))
		{
			if (!handle_color_ids(str, id, list, scene_info[x]))
				return (0);
		}
		else
			return (handle_invalid_identifier(id, str));
	}
	return (ids_found(list));
}
