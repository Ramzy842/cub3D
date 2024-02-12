/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ids_found.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:15:16 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 11:48:12 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ids_found(t_element *list)
{
	t_element	*current;

	current = list;
	while (current)
	{
		if (!current->found_status)
		{
			printf("\x1b[31mError\nMissing or incomplete information!\x1b[0m\n");
			return (0);
		}
		current = current->next;
	}
	return (1);
}
