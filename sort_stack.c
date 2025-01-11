/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:35:23 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:49:50 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*bigest_value(t_push_swap	*stack)
{
	t_push_swap	*bigest;

	bigest = stack;
	while (stack)
	{
		if (bigest->index < stack->index)
			bigest = stack;
		stack = stack->next;
	}
	return (bigest);
}

void	sort_3(t_push_swap	**stack)
{
	t_push_swap	*bigest;

	bigest = bigest_value(*stack);
	if (bigest == *stack)
		ra(stack);
	else if ((*stack)->next == bigest)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_stacks(t_push_swap **a, t_push_swap **b)
{
	int	len_a;

	len_a = stack_line(*a);
	if (len_a-- > 3)
		pb(a, b);
	if (len_a-- > 3)
		pb(a, b);
	while (len_a-- > 3)
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}