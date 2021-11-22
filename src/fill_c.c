/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:10:29 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/21 12:48:41 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/push_swap.h"
#include <limits.h>

#include <stdio.h>

int	find_smallest(t_stack *a, int sup)
{
	int	i;
	int	last;
	int	ret;

	i = 0;
	last = INT_MAX;
	ret = -1;
	while (i < a->size)
	{
		if (a->stack[i] <= last && (a->stack[i] > sup || \
				(a->stack[i] >= sup && sup == INT_MIN)))
		{
			last = a->stack[i];
			ret = i;
		}
		++i;
	}
	return (ret);
}

void	fill_c(t_stack *a, t_stack *c)
{
	int	i;

	i = 0;
	c->stack[i] = a->stack[find_smallest(a, INT_MIN)];
	while (++i < a->size)
		c->stack[i] = a->stack[find_smallest(a, c->stack[i - 1])];
}
