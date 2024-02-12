/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:16:42 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 14:57:51 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/cub3d.h"

void	search_and_free(t_scene *scene, t_Node *popped, int *void_found)
{
	search_void(popped, void_found, scene);
	free_stacks(scene, popped);
}

int	void_found(t_scene *scene, int x, int y, t_Node *popped)
{
	int		void_found;

	void_found = 0;
	push(scene->s, x, y);
	search_and_free(scene, popped, &void_found);
	return (void_found);
}

int	void_path(t_Node *popped, t_scene *scene)
{
	create_stacks(scene);
	if (void_found(scene, scene->player_x, scene->player_y, popped))
		return (1);
	return (0);
}

int	space_to_void_path(t_Node *popped, t_scene *scene)
{
	int		x;
	int		y;

	x = 0;
	while (scene->map[x])
	{
		y = 0;
		while (scene->map[x][y])
		{
			create_stacks(scene);
			if (scene->map[x][y] == '0')
			{
				if (void_found(scene, x, y, popped))
					return (1);
			}
			else
				free_stacks(scene, popped);
			y++;
		}
		x++;
	}
	return (0);
}

int	path_is_valid(t_scene *scene)
{
	t_Node	*popped;

	popped = NULL;
	if (void_path(popped, scene) || space_to_void_path(popped, scene))
		return (1);
	return (0);
}
