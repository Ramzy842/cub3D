/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:11:12 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 11:09:09 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	edit_node(t_element **list, char *id, char *path, char **colors)
{
	t_element	*current;

	current = *list;
	while (current)
	{
		if (!ft_strcmp(current->id, id))
		{
			if (!current->found_status)
			{
				current->found_status++;
				current->path = ft_strdup(path);
				current->colors = colors;
			}
		}
		current = current->next;
	}
}
