/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:52:49 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 07:59:33 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

void	put_a_top(t_stack *a, t_stack *b)
{
	int		i;
	t_rot	rot;

	i = 0;
	rot = rotate_;
	while (a->stack[i] != a->small && i < a->size)
		++i;
	if (i > (a->size / 2) + (a->size % 2))
	{
		rot = reverse_rotate;
		i = a->size - i;
	}
	while (i > 0)
	{
		if (rot == rotate_)
			rotate(a, b, RA, 0);
		else if (rot == reverse_rotate)
			rev_rotate(a, b, RRA, 0);
		--i;
	}
}

void	exec_mv_rot(t_stack *a, t_stack *b, \
		t_moves *a_mv, t_moves *b_mv)
{
	if (a_mv->rot == rotate_ && b_mv->rot == rotate_ && \
		a_mv->nb_rotations > 0 && b_mv->nb_rotations > 0)
	{
		--(a_mv->nb_rotations);
		--(b_mv->nb_rotations);
		rotate(a, b, RR, 1);
	}
	else if (a_mv->rot == rotate_ && a_mv->nb_rotations > 0)
	{
		--(a_mv->nb_rotations);
		rotate(a, b, RA, 0);
	}
	else if (b_mv->rot == rotate_ && b_mv->nb_rotations > 0)
	{
		--(b_mv->nb_rotations);
		rotate(b, a, RB, 0);
	}
}

void	exec_mv_rev_rot(t_stack *a, t_stack *b, \
		t_moves *a_mv, t_moves *b_mv)
{
	if (a_mv->rot == reverse_rotate && b_mv->rot == reverse_rotate && \
		a_mv->nb_reverse_rotations > 0 && b_mv->nb_reverse_rotations > 0)
	{
		--(a_mv->nb_reverse_rotations);
		--(b_mv->nb_reverse_rotations);
		rev_rotate(a, b, RRR, 1);
	}
	else if (a_mv->rot == reverse_rotate && a_mv->nb_reverse_rotations > 0)
	{
		--(a_mv->nb_reverse_rotations);
		rev_rotate(a, b, RRA, 0);
	}
	else if (b_mv->rot == reverse_rotate && b_mv->nb_reverse_rotations > 0)
	{
		--(b_mv->nb_reverse_rotations);
		rev_rotate(b, a, RRB, 0);
	}
}

void	move_stacks_for_push(t_stack *a, t_stack *b, \
		t_moves *a_mv, t_moves *b_mv)
{
	while (get_rot(a_mv) > 0 || get_rot(b_mv) > 0)
	{
		exec_mv_rot(a, b, a_mv, b_mv);
		exec_mv_rev_rot(a, b, a_mv, b_mv);
	}
}
