/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begins_with_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:31:07 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/15 10:57:04 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	begins_with_wall(char *str)
{
	if (str[0] != '1')
		return (0);
	return (1);
}