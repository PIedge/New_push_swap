/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:29:12 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:30:26 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/moves.h"
#include "../includes/utils.h"

int	make_push(t_stack *from, t_stack *to)
{
	int	i;

	if (from->size == 0)
		return (1);
	i = to->size + 1;
	while (--i > 0)
		(to->stack)[i] = (to->stack)[i - 1];
	to->stack[0] = from->stack[0];
	i = -1;
	while (++i < from->size - 1)
		(from->stack)[i] = (from->stack)[i + 1];
	--(from->size);
	++(to->size);
	return (1);
}

void	push(t_stack *from, t_stack *to, char *op)
{
	if (from->stack[0] > to->big || to->size == 0)
		to->big = from->stack[0];
	if (from->stack[0] < to->small || to->size == 0)
		to->small = from->stack[0];
	make_push(from, to);
	write(STDOUT_FILENO, op, ft_strlen(op));
}
