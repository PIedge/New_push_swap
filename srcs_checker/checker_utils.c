/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:22:55 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:37:23 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/checker.h"
#include <unistd.h>

int	search_apply(char *line, t_stack *a, t_stack *b)
{
	if (*line == 's')
		return (swap_checker(line, a, b));
	else if (*line == 'p')
		return (push_checker(line, a, b));
	else if (*line == 'r')
		return (rotate_checker(line, a, b));
	return (0);
}

int	final(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->size - 1)
		if ((a->stack)[i] > (a->stack)[i + 1])
			return (0);
	return (1);
}

int	get_next_order(t_stack *a, t_stack *b)
{
	char	*line;

	line = 0;
	a = 0;
	b = 0;
	return (1);
}
