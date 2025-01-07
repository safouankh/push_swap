/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:40:29 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/07 11:31:21 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*create_node(int value)
{
	t_push_swap	*node;

	node = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

int	stack_line(t_push_swap *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	helper(char **str, int tf)
{
	if (!check_sentacs(str + tf) 
		|| !check_numbers(str + tf) 
		|| !check_doplicates(str + tf) 
		|| !check_sort(str + tf))
	{
		if (tf == 0)
			free_str(str);
		write(1,"error\n",6);
		return (0);
	}
	return (1);
}

t_push_swap	*create_stack(char **str, int tf)
{
	int			value;
	t_push_swap	*head;
	t_push_swap	*current;
	t_push_swap	*node;

	head = NULL;
	current = NULL;
	if (helper(str, tf) == 0)
		exit(0);
	while (str[tf])
	{
		value = (int)ft_atoi(str[tf]);
		node = create_node(value);
		if (!head)
			head = node;
		else
		{
			current->next = node;
			node->prev = current;
		}
		current = node;
		tf++;
	}
	return (head);
}
