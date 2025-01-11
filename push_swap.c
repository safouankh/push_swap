/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:52:54 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:50:14 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push_swap	*a;
	t_push_swap	*b;
	int			tf;

	tf = (ac != 2);
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (ac == 2 && av[1][0] == '\0')
		return (write(2, "error", 5), 0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	a = create_stack(av, tf);
	if (stack_line(a) == 2)
		sa(&a);
	else if (stack_line(a) == 3)
		sort_3(&a);
	else
		sort_stacks(&a, &b);
}
