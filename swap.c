/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   swap.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sael-kha <sael-kha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/01/04 13:40:35 by sael-kha		  #+#	#+#			 */
/*   Updated: 2025/01/04 15:25:33 by sael-kha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
}
void	pa(t_push_swap **b, t_push_swap **a)
{
	t_push_swap	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
}