/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 04:09:18 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 07:25:44 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"

#include <stdio.h>

void	init_t_number(t_number *n)
{
	n->cost = 0;
	n->direction = 0;
	n->index = 0;
	n->number = 0;
}

int	not_sorted(t_stack *a)
{
	int	i;

	i = 1;
	while (i < a->size)
	{
		if (a->stack[i] < a->stack[i - 1])
			return (1);
		++i;
	}
	return (0);
}

int	find_place_cost_in_b(t_stack *s, t_number *n)
{
	int	i;
	int	mode;

	mode = 0;
	n->cost = 0;
	i = 0;
	if (s->size < 2)
		return (n->cost);
	if (n->number < s->small || n->number > s->big)
		mode = 1;
	while (i < s->size - 1)
	{
		if (mode && s->stack[i] == s->big)
			return (n->cost);
		if (!mode && i == 0 && (n->number > s->stack[0] && \
				n->number < s->stack[s->size - 1]))
			return (n->cost);
		if (!mode && (n->number < s->stack[i] && n->number > s->stack[i + 1]))
			return (++(n->cost));
		++(n->cost);
		++i;
	}
	return (n->cost);
}

void	get_big_small(t_stack *s)
{
	int	i;

	i = -1;
	s->small = s->stack[0];
	s->big = s->stack[0];
	while (++i < s->size)
	{
		if (s->small > s->stack[i])
			s->small = s->stack[i];
		else if (s->big < s->stack[i])
			s->big = s->stack[i];
	}
}
