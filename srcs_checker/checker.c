/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:39:01 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:41:55 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/moves.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"

#include <unistd.h>
#include <stdio.h>

int	swap_checker(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\0", 3))
		return (make_swap(a, b, 0));
	else if (!ft_strncmp(line, "sb\0", 3))
		return (make_swap(b, a, 0));
	else if (!ft_strncmp(line, "ss\0", 3))
		return (make_swap(b, a, 1));
	return (0);
}

int	push_checker(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "pa\0", 3))
		return (make_push(b, a));
	if (!ft_strncmp(line, "pb\0", 3))
		return (make_push(a, b));
	return (0);
}

int	rotate_checker(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "ra\0", 3))
		return (make_rotate(a, b, 0));
	else if (!ft_strncmp(line, "rb\0", 3))
		return (make_rotate(b, a, 0));
	else if (!ft_strncmp(line, "rr\0", 3))
		return (make_rotate(b, a, 1));
	else if (!ft_strncmp(line, "rra\0", 4))
		return (make_rev_rotate(a, b, 0));
	else if (!ft_strncmp(line, "rrb\0", 4))
		return (make_rev_rotate(b, a, 0));
	else if (!ft_strncmp(line, "rrr\0", 4))
		return (make_rev_rotate(b, a, 1));
	return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*line;
	int		test;

	line = 0;
	test = get_next_line(0, &line);
	while (test || *line)
	{
		if (!search_apply(line, a, b))
		{
			free(line);
			return (write(STDERR_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
		}
		free(line);
		test = get_next_line(0, &line);
	}
	free(line);
	if (b->size != 0 || !final(a))
	{
		write(STDERR_FILENO, "KO\n", 3);
		return (0);
	}
	return (write(STDERR_FILENO, "OK\n", 3));
}
