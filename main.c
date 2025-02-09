/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:05:23 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/09 10:45:04 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ret_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	handeler(int argc, char **argv, t_stack_node **a)
{
	int		i;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		stack_init(a, str);
		i++;
	}
}

void	heelper(t_stack_node **a, t_stack_node **b)
{
	indexer(a);
	range(a, b);
	sort_stack(a, b);
}

void	set_target_node(t_stack_node *a,
							t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = ret_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

int	main(int ac, char *av[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		stack_init(&a, av);
	}
	else
		handeler(ac, av, &a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) <= 3)
			sort_3(&a);
		else if (stack_len(a) <= 15)
			sort_5(&a, &b);
		else
			heelper(&a, &b);
	}
	free_stack(&a);
}
