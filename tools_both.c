/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_both.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:24:46 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:51:19 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*get_cheapest(t_push_swap *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_push_swap **stack, t_push_swap *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

void	rotate_both(t_push_swap **a, t_push_swap **b, t_push_swap *cheap)
{
	while (*b != cheap->target_node
		&& *a != cheap)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rr_both(t_push_swap **a, t_push_swap **b, t_push_swap *cheap)
{
	while (*b != cheap->target_node
		&& *a != cheap)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
