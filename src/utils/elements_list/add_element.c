/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:11:02 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 11:10:05 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	add_element(t_element **list, char *id, char *path, char **colors)
{
	t_element	*element;
	t_element	*current;

	element = malloc(sizeof(t_element));
	if (!element)
		return ;
	element->found_status = 0;
	element->id = ft_strdup(id);
	element->path = ft_strdup(path);
	element->colors = colors;
	element->next = NULL;
	if (!*list)
	{
		*list = element;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = element;
}
