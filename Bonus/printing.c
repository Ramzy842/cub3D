/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:29:09 by rchahban          #+#    #+#             */
/*   Updated: 2024/02/10 23:53:06 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	print_char(char c)
{
	if (c == '1')
		printf("\x1b[31m%c\x1b[0m", c);
	else if (c == '0')
		printf("\x1b[32m%c\x1b[0m", c);
	else if (is_player(c))
		printf("\x1b[35m%c\x1b[0m", c);
	else
		printf("%c", c);
}

void	print_2d_arr(char **colors)
{
	int	x;

	x = 0;
	while (colors[x])
	{
		printf("%s\n", colors[x]);
		x++;
	}
	printf("-------------------------------------\n");
}

void	display_list(t_element *head)
{
	t_element	*current;
	int			x;

	current = head;
	while (current)
	{
		printf("id: %s\n", current->id);
		printf("Found Status: %d\n", current->found_status);
		printf("Path: %s\n", current->path);
		if (current->colors)
		{
			x = 0;
			printf("Colors: [");
			while (current->colors[x])
			{
				printf("%s", current->colors[x]);
				if (current->colors[x + 1])
					printf(",");
				x++;
			}
			printf("]\n");
		}
		current = current->next;
	}
}
