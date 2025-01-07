/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sael-kha <sael-kha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/04 11:45:42 by sael-kha		  #+#	#+#			 */
/*   Updated: 2025/01/06 14:42:30 by sael-kha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_list_forward(t_push_swap *head) {
	t_push_swap *current = head;
	while (current) 
	{
		printf("nbr = %d index = %d <-> ", current->value, current->index);
		current = current->next;
	}
	printf("NULL\n");
}

int index_helper(t_push_swap *stack, int value)
{
	int i;
	t_push_swap *curent;

	curent = stack;
	i = 0;
	while(curent)
	{
		if (value > curent->value)
			i++;
		curent = curent->next;
	}
	return i;
}

void	indexer(t_push_swap *stack)
{
	int nbr;
	int i;

	i = 0;
	t_push_swap *current = stack;
	while(current)
	{
		i = index_helper(stack,current->value);
		current->index = i;
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_push_swap	*a;
	t_push_swap	*b;
	int tf;

	tf = (ac != 2);
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (write(1, "error", 5), 0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	a = create_stack(av, tf);
	indexer(a);
	print_list_forward(a);
}
