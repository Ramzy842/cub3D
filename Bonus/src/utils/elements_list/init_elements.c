/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:10:46 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/27 11:42:53 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_elements(t_element **elements)
{
	*elements = NULL;
	add_element(elements, "NO", NULL, NULL);
	add_element(elements, "WE", NULL, NULL);
	add_element(elements, "EA", NULL, NULL);
	add_element(elements, "SO", NULL, NULL);
	add_element(elements, "C", NULL, NULL);
	add_element(elements, "F", NULL, NULL);
}
