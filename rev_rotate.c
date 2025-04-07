/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:18:43 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 20:35:34 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
	{
		printf("Reverse rotate skipped: Stack is empty or has one element.\n");
		return ;
	}
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	printf("Reverse rotated stack: Top element is now %d.\n", (*stack)->nbr);
}

void	rra(t_stack_node **a, t_bool print)
{
	rev_rotate(a);
	if (!print)
		printf("rra\n");
}

void	rrb(t_stack_node **b, t_bool print)
{
	rev_rotate(b);
	if (!print)
		printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, t_bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		printf("rrr\n");
}
