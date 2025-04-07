/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:18:55 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 20:35:34 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
	{
		printf("Rotate skipped: Stack is empty or has one element.\n");
		return ;
	}
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	printf("Rotated stack: Top element is now %d.\n", (*stack)->nbr);
}		

void	ra(t_stack_node **a, t_bool print)
{
	rotate(a);
	if (!print)
		printf("ra\n");
}

void	rb(t_stack_node **b, t_bool print)
{
	rotate(b);
	if (!print)
		printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		printf("rr\n");
}
