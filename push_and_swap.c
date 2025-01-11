/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:30:05 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:52:22 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*temp;

	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	write(1, "pb\n", 3);
}

void	pa(t_push_swap **b, t_push_swap **a)
{
	t_push_swap	*temp;

	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	write(1, "pa\n", 3);
}

void	sa(t_push_swap **a)
{
	t_push_swap	*temp;

	temp = *a;
	if (!(*a)->next || !(*a)->next->next)
		return ;
	*a = (*a)->next;
	temp->next = (*a)->next;
	temp->prev = *a;
	(*a)->next->prev = temp;
	(*a)->next = temp;
	(*a)->prev = NULL;
	write(1, "sa\n", 3);
}

void	sb(t_push_swap **b)
{
	t_push_swap	*temp;

	temp = *b;
	if (!(*b)->next || !(*b)->next->next)
		return ;
	*b = (*b)->next;
	temp->next = (*b)->next;
	temp->prev = *b;
	(*b)->next->prev = temp;
	(*b)->next = temp;
	(*b)->prev = NULL;
	write(1, "sb\n", 3);
}

void	ra(t_push_swap **a)
{
	t_push_swap	*temp;
	t_push_swap	*current;

	current = *a;
	temp = *a;
	*a = (*a)->next;
	while (current->next)
		current = current->next;
	temp->next->prev = NULL;
	current->next = temp;
	temp->prev = current;
	temp->next = NULL;
	write(1, "ra\n", 3);
}
