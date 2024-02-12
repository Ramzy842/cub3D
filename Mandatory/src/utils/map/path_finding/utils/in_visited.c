/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_visited.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:55:46 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/14 22:56:06 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/cub3d.h"

int	in_visited(t_Stack	*visited, int a, int b)
{
	t_Node	*temp;

	if (is_empty(visited))
		return (0);
	else
	{
		temp = visited->top;
		while (temp != NULL)
		{
			if (a == temp->x && b == temp->y)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}
