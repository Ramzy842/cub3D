/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:04:05 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 11:04:04 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	free_list(t_element *list)
{
	t_element	*temp;
	t_element	*next_node;

	temp = list;
	next_node = NULL;
	while (temp)
	{
		next_node = temp->next;
		free(temp->id);
		if (temp->path)
			free(temp->path);
		if (temp->colors)
			free_2d_arr(temp->colors);
		free(temp);
		temp = next_node;
	}
}
