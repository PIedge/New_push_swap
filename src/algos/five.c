/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:17:26 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 10:40:51 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

static int	new_range_five(int i, t_stack *c)
{
	if ((c->size / 4) * i >= c->size)
		return (c->stack[c->size - 1]);
	return (c->stack[(c->size / 4) * i]);
}

void	yup(t_stack *a, t_stack *b, t_stack *c)
{
	int			i;
	int			range;
	t_number	n;
	t_moves		b_mv;

	i = 1;
	range = new_range_five(i++, c);
	while (not_sorted(a))
	{
		if (left_from_range(a, range))
			range = new_range_five(i++, c);
		find_next(a, &n, range);
		how_much_moves(a, b, &n, &b_mv);
		if (n.index == 0)
			setup_b(b, a, &b_mv);
		else if (b_mv.nb_rotations == 0)
			move_a(a, b, &n.mv);
		else
			move_stacks_for_push(a, b, &n.mv, &b_mv);
		push(a, b, PB);
		if (a->size == 3)
			three(a, b);
	}
}

void	five(t_stack *a, t_stack *b, t_stack *c)
{
	yup(a, b, c);
	while (b->size > 0)
	{
		setup_for_push(a, b);
		push(b, a, PA);
		put_a_top(a, b);
	}
}
