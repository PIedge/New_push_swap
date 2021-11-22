/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:23:23 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:29:58 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/utils.h"
#include <unistd.h>

int	make_rotate(t_stack *manip, t_stack *useless, int mode)
{
	int	first;
	int	i;

	if (manip->size < 2)
		return (1);
	first = (manip->stack)[0];
	i = -1;
	while (++i < manip->size -1)
		(manip->stack)[i] = (manip->stack)[i + 1];
	(manip->stack)[i] = first;
	if (mode)
		make_rotate(useless, manip, 0);
	return (1);
}

void	rotate(t_stack *manip, t_stack *useless, char *op, int mode)
{
	make_rotate(manip, useless, mode);
	write(STDOUT_FILENO, op, ft_strlen(op));
}
