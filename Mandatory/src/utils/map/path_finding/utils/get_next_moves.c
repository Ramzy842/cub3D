/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:14:10 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 16:20:15 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/cub3d.h"

void	get_next_moves(t_Stack *s, int a, int b, t_scene *scene)
{
	if (a > 0 && (scene->map[a - 1][b] != '1'))
		push(s, a - 1, b);
	if (b < scene->map_cols
		&& (scene->map[a][b + 1] != '1'))
		push(s, a, b + 1);
	if (a < scene->map_rows
		&& (scene->map[a + 1][b] != '1'))
		push(s, a + 1, b);
	if (b > 0 && (scene->map[a][b - 1] != '1'))
		push(s, a, b - 1);
}
