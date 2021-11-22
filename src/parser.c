/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:48:48 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 12:39:50 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"
#include <limits.h>

static int	malloc_all(t_stack *a, t_stack *b, t_stack *c, int len)
{
	a->size = len;
	b->size = 0;
	c->size = len;
	a->stack = malloc(sizeof(int) * len);
	if (!(a->stack))
		return (0);
	b->stack = malloc(sizeof(int) * len);
	if (!(b->stack))
		return (0);
	c->stack = malloc(sizeof(int) * len);
	if (!(c->stack))
		return (0);
	return (1);
}

static int	fill_up(t_stack *a, char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
		a->stack[i] = ft_atoi(av[i]);
	i = -1;
	a->big = a->stack[0];
	a->small = a->stack[0];
	while (++i < a->size)
	{
		if (a->big < a->stack[i])
			a->big = a->stack[i];
		if (a->small > a->stack[i])
			a->small = a->stack[i];
		j = i;
		while (++j < a->size)
			if (a->stack[i] == a->stack[j])
				return (0);
	}
	i = -1;
	return (1);
}

static int	check_bigger(char **av, int i, int j)
{
	char	*val;

	if (ft_strlen(av[j]) < 10)
		return (1);
	if (ft_atol(av[j]) > INT_MAX || ft_atol(av[j]) < INT_MIN)
		return (0);
	i = -1;
	if (av[j][0] == '-')
		val = ft_itoa(INT_MIN);
	else
		val = ft_itoa(INT_MAX);
	if (!val)
		return (0);
	while (val[++i])
	{
		if (av[j][i] > val[i])
		{
			free(val);
			return (0);
		}
	}
	return (1);
}

static int	check_phony(char **av)
{
	int	i;
	int	j;

	j = -1;
	if (!(av[0]) || !((av[0][0] >= '0' && av[0][0] <= '9') || \
			av[0][0] == '-'))
		return (0);
	while (av[++j])
	{
		i = -1;
		if (av[j][0] == '-')
			++i;
		while (av[j][++i])
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
				return (0);
		if (!check_bigger(av, i, j))
			return (0);
	}
	return (1);
}

int	parser(char **av, t_stack *a, t_stack *b, t_stack *c)
{
	int	len;

	len = 0;
	while (av[len])
		++len;
	if (!check_phony(av))
		return (0);
	if (!malloc_all(a, b, c, len))
		return (0);
	if (!fill_up(a, av))
		return (0);
	fill_c(a, c);
	return (1);
}
