/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:20:22 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 20:23:20 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, FALSE);
	else if ((*a)->next == biggest_node)
		rra(a, FALSE);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, FALSE);
}
