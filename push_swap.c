/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:07:34 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 21:54:59 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pre_stack(int ac, char **av, t_stack_node **a, char ***split_res)
{
	char	**args;

	if (ac == 2 && av[1][0] == '\0')
		return (write(2, "Error\n", 6), 1);
	if (ac == 1 || (ac == 2 && (!av[1][0] || !av[1][1])))
		return (1);
	if (ac == 2 && is_only_spaces(av[1]))
	{	
		write(2, "Error\n", 6);
		return (1);
	}
	if (ac == 2)
	{
		*split_res = split(av[1], ' ');
		if (!*split_res)
			return (1);
		args = *split_res;
	}
	else
		args = av + 1;
	init_stack_a(a, args, split_res);
	return (0);
}

static void	sort_clean(t_stack_node **a, t_stack_node **b, char **split_res)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a, FALSE);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stacks(a, b);
	}
	free_stack(a);
	if (split_res)
		free_split_result(split_res);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_result;

	a = NULL;
	b = NULL;
	split_result = NULL;
	if (pre_stack(argc, argv, &a, &split_result))
	{
		return (1);
	}
	sort_clean(&a, &b, split_result);
	return (0);
}
