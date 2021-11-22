/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:07:40 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:30:03 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/utils.h"
#include <unistd.h>

int	make_rev_rotate(t_stack *manip, t_stack *useless, int mode)
{
	int	last;
	int	i;

	if (manip->size < 2)
		return (1);
	i = manip->size;
	last = (manip->stack)[i - 1];
	while (--i)
		(manip->stack)[i] = (manip->stack)[i - 1];
	(manip->stack)[i] = last;
	if (mode)
		make_rev_rotate(useless, manip, 0);
	return (1);
}

void	rev_rotate(t_stack *manip, t_stack *useless, char *op, int mode)
{
	make_rev_rotate(manip, useless, mode);
	write(STDOUT_FILENO, op, ft_strlen(op));
}
