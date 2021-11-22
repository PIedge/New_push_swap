/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:16:44 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:10:31 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

int	return_smallest(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

void	should_we_sync(t_moves *a, t_moves *b)
{
	int	optimum;
	int	same_dir;

	same_dir = 1;
	if (a->rot == b->rot)
	{
		same_dir = 0;
		optimum = get_rot(a) + get_rot(b) - \
			return_smallest(get_rot(a), get_rot(b));
	}
	else
		optimum = get_rot(a) + get_rot(b);
	if (optimum > (get_rev_rot(a) + get_rot(b) - \
			(return_smallest(get_rev_rot(a), get_rot(b)) * same_dir)))
		reverse_t_rot(a);
	else if (optimum > (get_rev_rot(b) + get_rot(a) - \
			(return_smallest(get_rev_rot(a), get_rot(b)) * same_dir)))
		reverse_t_rot(b);
}

void	how_much_moves(t_stack *a, t_stack *b, t_number *n, t_moves *b_mv)
{
	n->mv.nb_rotations = n->index;
	n->mv.nb_reverse_rotations = a->size - n->mv.nb_rotations;
	b_mv->nb_rotations = find_place_cost_in_b(b, n);
	b_mv->nb_reverse_rotations = b->size - b_mv->nb_rotations;
	n->mv.rot = rotate_;
	b_mv->rot = rotate_;
	if (n->mv.nb_rotations > n->mv.nb_reverse_rotations)
		n->mv.rot = reverse_rotate;
	if (b_mv->nb_rotations > b_mv->nb_reverse_rotations)
		b_mv->rot = reverse_rotate;
	should_we_sync(&(n->mv), b_mv);
}
