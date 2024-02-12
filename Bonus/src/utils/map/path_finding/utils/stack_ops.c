/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 22:54:21 by rchahban          #+#    #+#             */
/*   Updated: 2024/01/25 15:48:29 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../../includes/cub3d.h"

void	push(t_Stack *stack, int x, int y)
{
	t_Node	*new_node;

	new_node = malloc(sizeof(t_Node));
	if (!new_node)
		return ;
	new_node->x = x;
	new_node->y = y;
	new_node->next = stack->top;
	stack->top = new_node;
}

t_Stack	*create_stack(void)
{
	t_Stack	*stack;

	stack = malloc(sizeof(t_Stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	return (stack);
}

int	is_empty(t_Stack *stack)
{
	return (stack->top == NULL);
}

t_Node	*pop(t_Stack *stack)
{
	t_Node	*temp;

	if (is_empty(stack))
		return (NULL);
	temp = stack->top;
	if (!temp)
		return (NULL);
	stack->top = stack->top->next;
	temp->next = NULL;
	return (temp);
}
