/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_already_found.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:35:40 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/26 12:45:50 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_already_found(t_element *list, char *id, char *str)
{
	t_element	*current;

	current = list;
	while (current)
	{
		if (!ft_strcmp(current->id, id) && current->found_status)
		{
			printf("\x1b[31mError\nElement %s already found!\x1b[0m\n", id);
			if (str)
				free(str);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
