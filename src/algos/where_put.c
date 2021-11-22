/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:43:55 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 10:41:11 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

void	setup_b(t_stack *b, t_stack *a, t_moves *mv)
{
	if (mv->nb_rotations > mv->nb_reverse_rotations)
		while ((mv->nb_reverse_rotations--) > 0)
			rev_rotate(b, a, RRB, 0);
	else
		while ((mv->nb_rotations--) > 0)
			rotate(b, a, RB, 0);
}

void	move_a(t_stack *a, t_stack *b, t_moves *mv)
{
	if (mv->nb_rotations > mv->nb_reverse_rotations)
		while ((mv->nb_reverse_rotations--) > 0)
			rev_rotate(a, b, RRA, 0);
	else
		while ((mv->nb_rotations--) > 0)
			rotate(a, b, RA, 0);
}

int	is_a_ready_for_push(t_stack *a, t_stack *b)
{
	int	i;

	get_big_small(a);
	i = 1;
	if (a->big < b->big)
		return (0);
	if (a->stack[0] > b->big)
		return (0);
	while (i < a->size)
	{
		if (b->big > a->stack[i - 1] && b->big < a->stack[i])
			return (i);
		++i;
	}
	return (i);
}

int	is_b_ready_for_push(t_stack *b)
{
	int	i;

	i = 0;
	while (b->stack[i] != b->big && i < b->size)
		++i;
	return (i);
}

void	setup_for_push(t_stack *a, t_stack *b)
{
	t_moves	a_mv;
	t_moves	b_mv;

	get_big_small(a);
	get_big_small(b);
	a_mv.nb_rotations = is_a_ready_for_push(a, b);
	b_mv.nb_rotations = is_b_ready_for_push(b);
	a_mv.nb_reverse_rotations = a->size - a_mv.nb_rotations;
	b_mv.nb_reverse_rotations = b->size - b_mv.nb_rotations;
	a_mv.rot = rotate_;
	b_mv.rot = rotate_;
	if (a_mv.nb_rotations > a_mv.nb_reverse_rotations)
		a_mv.rot = reverse_rotate;
	if (b_mv.nb_rotations > b_mv.nb_reverse_rotations)
		b_mv.rot = reverse_rotate;
	should_we_sync(&a_mv, &b_mv);
	if (a_mv.nb_rotations == 0)
		setup_b(b, a, &b_mv);
	else if (b_mv.nb_rotations == 0)
		move_a(a, b, &a_mv);
	else
		move_stacks_for_push(a, b, &a_mv, &b_mv);
}
