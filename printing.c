/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:29:09 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 13:42:00 by rchahban         ###   ########.fr       */
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

void	print_map(char **map)
{
	int	x;
	int	y;

	if (!map)
	{
		printf("no map present in file\n");
		return ;
	}
	x = 0;
	printf("------------------- MAP --------------------\n");
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			print_char(map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
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
