/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:49:42 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/11 16:49:27 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_push_swap;

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *s);
long long	ft_atoi(const char *str);

int			stack_line(t_push_swap *stack);
t_push_swap	*create_node(int value);
t_push_swap	*create_stack(char **str, int tf);

int			check_numbers(char **str);
int			is_valid_number(const char *s);
int			check_sentacs(char **str);
int			check_doplicates(char **str);
int			check_sort(char **str);
void		free_str(char **str);

void		pb(t_push_swap **a, t_push_swap **b);
void		pa(t_push_swap **b, t_push_swap **a);
void		sa(t_push_swap **a);
void		sb(t_push_swap **b);
void		ra(t_push_swap **a);
void		rb(t_push_swap **b);
void		rr(t_push_swap **a, t_push_swap **b);
void		rra(t_push_swap **a);
void		rrb(t_push_swap **b);
void		rrr(t_push_swap **a, t_push_swap **b);

void		sort_3(t_push_swap	**stack);
void		sort_stacks(t_push_swap **a, t_push_swap **b);

void		set_cheapest(t_push_swap *stack);
void		set_target_a(t_push_swap *a, t_push_swap *b);
t_push_swap	*find_max(t_push_swap *stack);
t_push_swap	*find_min(t_push_swap *stack);

t_push_swap	*get_cheapest(t_push_swap *stack);
void		prep_for_push(t_push_swap **stack, t_push_swap *top, char name);
void		rotate_both(t_push_swap **a, t_push_swap **b, t_push_swap *cheap);
void		rr_both(t_push_swap **a, t_push_swap **b, t_push_swap *cheap);
void		current_index(t_push_swap *stack);

void		cost_analysis_a(t_push_swap *a, t_push_swap *b);
void		set_target_a(t_push_swap *a, t_push_swap *b);
void		init_nodes_a(t_push_swap *a, t_push_swap *b);

void		min_on_top(t_push_swap **a);
void		move_b_to_a(t_push_swap **a, t_push_swap **b);
void		init_nodes_b(t_push_swap *a, t_push_swap *b);
void		set_target_b(t_push_swap *a, t_push_swap *b);
void		move_a_to_b(t_push_swap **a, t_push_swap **b);

#endif