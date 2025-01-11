/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:40:15 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:50:51 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_push_swap **b)
{
	t_push_swap	*temp;
	t_push_swap	*current;

	current = *b;
	temp = *b;
	*b = (*b)->next;
	while (current->next)
		current = current->next;
	temp->next->prev = NULL;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_push_swap **a, t_push_swap **b)
{
	ra(a);
	rb(b);
}

void	rra(t_push_swap **a)
{
	t_push_swap	*current;

	current = (*a);
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	(*a)->prev = current;
	current->next = (*a);
	(*a) = current;
	write(1, "rra\n", 4);
}

void	rrb(t_push_swap **b)
{
	t_push_swap	*current;

	current = (*b);
	while (current->next)
		current = current->next;
	current->prev->next = NULL;
	current->prev = NULL;
	(*b)->prev = current;
	current->next = (*b);
	(*b) = current;
	write(1, "rrb\n", 4);
}

void	rrr(t_push_swap **a, t_push_swap **b)
{
	rra(a);
	rrb(b);
}
