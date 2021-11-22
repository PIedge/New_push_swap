/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:40:34 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 11:49:50 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/moves.h"
#include "../../includes/push_swap.h"

void	under_three(t_stack *a, t_stack *b)
{
	if (a->size > 1 && a->stack[0] > a->stack[1])
		swap(a, b, SA, 0);
}

void	for_the_norm(t_stack *a, t_stack *b, int mode)
{
	swap(a, b, SA, 0);
	if (!mode)
		rotate(a, b, RA, 0);
	else
		rev_rotate(a, b, RRA, 0);
}

void	three(t_stack *a, t_stack *b)
{
	int	*stack;

	stack = a->stack;
	if (a->size == 2 && a->stack[0] > a->stack[1])
		swap(a, b, SA, 0);
	if (a->size == 3)
	{
		if (stack[0] > stack[1] && stack[1] > stack[2])
			for_the_norm(a, b, 1);
		else if (stack[0] < stack[1] && stack[1] > stack[2] && \
				stack[0] < stack[2])
			for_the_norm(a, b, 0);
		else if (stack[0] < stack[1] && stack[1] > stack[2] && \
				stack[0] > stack[2])
			rev_rotate(a, b, RRA, 0);
		else if (stack[0] > stack[1] && stack[1] < stack[2] && \
				stack[0] < stack[2])
			swap(a, b, SA, 0);
		else if (stack[0] > stack[1] && stack[1] < stack[2] && \
				stack[0] > stack[2])
			rotate(a, b, RA, 0);
	}
}
