/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:56:15 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/21 14:13:12 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

void	reverse_t_rot(t_moves *mv)
{
	if (mv->rot == rotate_)
		mv->rot = reverse_rotate;
	else
		mv->rot = rotate_;
}

int	get_rev_rot(t_moves *mv)
{
	if (mv->rot == rotate_)
		return (mv->nb_reverse_rotations);
	return (mv->nb_rotations);
}

int	get_rot(t_moves *mv)
{
	if (mv->rot == rotate_)
		return (mv->nb_rotations);
	return (mv->nb_reverse_rotations);
}
