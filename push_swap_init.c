/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:05:20 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/09 13:17:52 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

int	index_helper(t_stack_node **a, t_stack_node *node)
{
	t_stack_node	*curent;
	int				i;

	i = 0;
	curent = *a;
	while (curent)
	{
		if (node->value > curent->value)
			i++;
		curent = curent->next;
	}
	return (i);
}

void	range(t_stack_node **a, t_stack_node **b)
{
	int	min;
	int	max;

	min = 0;
	max = 0.048 * stack_len(*a) + 10;
	while (*a)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb(b, a, false);
			max++;
			min++;
		}
		else if ((*a)->index < min)
		{
			pb(b, a, false);
			rb(b, false);
			max++;
			min++;
		}
		else
			ra(a, false);
	}
}

t_stack_node	*ret_big(t_stack_node *stack)
{
	t_stack_node	*big_one;
	t_stack_node	*curent;

	big_one = stack;
	curent = stack;
	while (curent)
	{
		if (big_one->value < curent->value)
			big_one = curent;
		curent = curent->next;
	}
	return (big_one);
}
