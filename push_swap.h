/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:05:54 by sael-kha          #+#    #+#             */
/*   Updated: 2025/02/08 18:23:43 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	bool				above_median;
	int					index;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

//*** ft_split utils ***
char			**ft_split(char *s, char c);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
size_t			ft_strlen(char *s);

//*** Handle errors-free ***
void			free_matrix(char **argv);
void			error_free(t_stack_node **a, char **argv);
void			free_stack(t_stack_node **stack);
int				error_repetition(t_stack_node *a, int nbr);
int				error_syntax(char *str_nbr);

//*** linked list utils ***
void			stack_init(t_stack_node **a, char **argv);
void			set_current_position(t_stack_node *stack);
void			append_node(t_stack_node **stack, int nbr);
bool			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*ret_smallest(t_stack_node *stack);
void	set_target_node(t_stack_node *a, t_stack_node *b);

//*** Algorithms ***
void			sort_3(t_stack_node **a);
int				index_helper(t_stack_node **a, t_stack_node *node);
void			indexer(t_stack_node **a);
void			range(t_stack_node **a, t_stack_node **b);
t_stack_node	*ret_big(t_stack_node *stack);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_5(t_stack_node **a, t_stack_node **b);

//*** Commands ***
void			sa(t_stack_node **a, bool checker);
void			sb(t_stack_node **b, bool checker);
void			ss(t_stack_node **a, t_stack_node **b, bool checker);
void			ra(t_stack_node **a, bool checker);
void			rb(t_stack_node **b, bool checker);
void			rr(t_stack_node **a, t_stack_node **b, bool checker);
void			rra(t_stack_node **a, bool checker);
void			rrb(t_stack_node **b, bool checker);
void			rrr(t_stack_node **a, t_stack_node **b, bool checker);
void			pa(t_stack_node **a, t_stack_node **b, bool checker);
void			pb(t_stack_node **b, t_stack_node **a, bool checker);

#endif
