/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:46:49 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 15:56:20 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/cub3d.h"

void	free_stacks(t_scene *scene, t_Node *popped)
{
	free_stack(scene->visited);
	free_stack(scene->s);
	free_nodes(popped);
}
