/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:49:42 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/07 11:18:25 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct t_push_swap
{
	int					index;
	struct t_push_swap	*prev;
	int					value;
	struct t_push_swap	*next;
}			t_push_swap;

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);
int			stack_line(t_push_swap *stack);
void		link_nodes(t_push_swap *node1, t_push_swap *node2);
t_push_swap	*create_node(int value);
t_push_swap	*create_stack(char **str, int tf);
int			check_numbers(char **str);
int			is_valid_number(const char *s);
int			check_sentacs(char **str);
int			check_doplicates(char **str);
int			check_sort(char **str);
void		free_str(char **str);

#endif