/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-hmi <zait-hmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:34:03 by zait-hmi          #+#    #+#             */
/*   Updated: 2025/04/07 23:25:50 by zait-hmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	t_bool				above_median;
	t_bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				ft_isdigit(int c);
void			min_on_top(t_stack_node **a);

int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **stack, char ***split_res);
void			free_split_result(char **result_array);
int				is_only_spaces(char *str);

void			init_stack_a(t_stack_node **a, char **argv, char ***split_res);
char			**split(char *s, char c);

void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

void			sa(t_stack_node **a, t_bool print);
void			sb(t_stack_node **b, t_bool print);
void			ss(t_stack_node **a, t_stack_node **b, t_bool print);
void			ra(t_stack_node **a, t_bool print);
void			rb(t_stack_node **b, t_bool print);
void			rr(t_stack_node **a, t_stack_node **b, t_bool print);
void			rra(t_stack_node **a, t_bool print);
void			rrb(t_stack_node **b, t_bool print);
void			rrr(t_stack_node **a, t_stack_node **b, t_bool print);
void			pa(t_stack_node **a, t_stack_node **b, t_bool print);
void			pb(t_stack_node **b, t_stack_node **a, t_bool print);

void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

#endif