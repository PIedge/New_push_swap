/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:00:32 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:29:52 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/utils.h"
#include <unistd.h>

#include <stdio.h>

int	make_swap(t_stack *manip, t_stack *useless, int mode)
{
	int	buff;

	if (manip->size < 2)
		return (1);
	buff = (manip->stack)[0];
	(manip->stack)[0] = (manip->stack)[1];
	(manip->stack)[1] = buff;
	if (mode)
		make_swap(useless, manip, 0);
	return (1);
}

void	swap(t_stack *manip, t_stack *useless, char *op, int mode)
{
	make_swap(manip, useless, mode);
	write(STDOUT_FILENO, op, ft_strlen(op));
}
