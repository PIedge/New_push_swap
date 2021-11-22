/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:02 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 10:41:03 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

void	find_next(t_stack *a, t_number *n, int range)
{
	int	i;

	i = 0;
	while (i < (a->size / 2) + (a->size % 2))
	{
		if (a->stack[i] <= range)
		{
			n->number = a->stack[i];
			n->index = i;
			return ;
		}
		else if (a->stack[a->size - i - 1] <= range)
		{
			n->number = a->stack[a->size - i - 1];
			n->index = a->size - i - 1;
			return ;
		}
		++i;
	}
}

int	left_from_range(t_stack *a, int range)
{
	int	i;

	i = -1;
	while (++i < a->size)
	{
		if (a->stack[i] <= range)
			return (0);
	}
	return (1);
}

int	new_range(int i, t_stack *c)
{
	if ((c->size / 10) * i >= c->size)
		return (c->stack[c->size - 1]);
	return (c->stack[(c->size / 10) * i]);
}
