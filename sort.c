/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:05:08 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/09 10:46:33 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	indexer(t_stack_node **a)
{
	t_stack_node	*curent;

	curent = *a;
	while (curent)
	{
		curent->index = index_helper(a, curent);
		curent = curent->next;
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*big_one;

	while (*b)
	{
		big_one = ret_big(*b);
		set_current_position(*b);
		if (big_one->above_median)
		{
			while (big_one != *b)
				rb(b, false);
			pa(a, b, false);
		}
		else
		{
			while (big_one != *b)
				rrb(b, false);
			pa(a, b, false);
		}
	}
}

void	sort_3(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = ret_big(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smalest;

	while (stack_len(*a) > 3)
		pb(b, a, 0);
	sort_3(a);
	while (*b)
	{
		set_current_position(*a);
		set_target_node(*a, *b);
		if ((*b)->target_node->above_median)
			while ((*b)->target_node != *a)
				ra(a, 0);
		else
			while ((*b)->target_node != *a)
				rra(a, 0);
		pa(a, b, 0);
	}
	set_current_position(*a);
	smalest = ret_smallest(*a);
	if (smalest->above_median)
		while (smalest != *a)
			ra(a, 0);
	else
		while (smalest != *a)
			rra(a, 0);
}
