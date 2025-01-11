/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sael-kha <sael-kha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:38:43 by sael-kha          #+#    #+#             */
/*   Updated: 2025/01/07 10:39:33 by sael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_numbers(char **str)
{
	long long	value;
	int			i;

	i = 0;
	while (str[i] != NULL)
	{
		value = ft_atoi(str[i]); 
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_number(const char *s)
{
	int	has_digits;

	has_digits = 0;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		has_digits = 1;
		s++;
	}
	return (has_digits);
}

int	check_sentacs(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (is_valid_number(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_doplicates(char **str)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	while (str[i])
	{
		j = 0;
		nbr = ft_atoi(str[i]);
		while (str[j])
		{
			if (nbr == ft_atoi(str[j]) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sort(char **str)
{
	int	i;
	int	nbr1;

	i = 0;
	while (str[i] && str[i + 1])
	{
		nbr1 = ft_atoi(str[i]);
		if (nbr1 > ft_atoi(str[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
