/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:31:37 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 14:04:11 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	valid_map(char **initial_map, t_scene *scene)
{
	if (!initial_map || !scene)
		return (0);
	if (map_contains_correct_possible_chars(initial_map)
		&& map_is_sorrounded_by_walls(scene->map)
		&& map_contains_player(scene->map)
		&& !path_is_valid(scene))
	{
		free_2d_arr(initial_map);
		return (1);
	}
	free_2d_arr(initial_map);
	printf("\x1b[31mError\nInvalid map!\x1b[0m\n");
	return (0);
}
