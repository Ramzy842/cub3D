/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:12:57 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:19 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/cub3d.h"

void	search_void(t_Node *popped, int *void_found, t_scene *scene)
{
	int		x;
	int		y;

	while (!is_empty(scene->s))
	{
		popped = pop(scene->s);
		if (popped != NULL)
		{
			x = popped->x;
			y = popped->y;
			free_nodes(popped);
		}
		if (in_visited(scene->visited, x, y))
			continue ;
		else
		{
			push(scene->visited, x, y);
			if (in_visited(scene->visited, x, y) && scene->map[x][y] == 'V')
				(*void_found)++;
			if (*void_found)
				break ;
			get_next_moves(scene->s, x, y, scene);
		}
	}
}
