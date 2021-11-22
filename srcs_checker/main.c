/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 04:42:45 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 09:01:05 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "../includes/checker.h"
#include "../includes/moves.h"
#include "../includes/utils.h"
#include <stdlib.h>
#include <stdio.h>

static int	check_bigger(char **av, int i, int j)
{
	char	*val;

	if (ft_strlen(av[j]) < 10)
		return (1);
	if (ft_strlen(av[j]) > 11 || (ft_strlen(av[j]) > 10 && av[j][0] != '-'))
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

static int	check_for_phony(char **av)
{
	int	i;
	int	j;
	int	g;

	j = 0;
	while (av[++j])
	{
		i = -1;
		if (av[j][0] == '-')
			++i;
		while (av[j][++i])
			if (!(av[j][i] >= '0' && av[j][i] <= '9'))
				return (0);
		g = j;
		if (!check_bigger(av, i, j))
			return (0);
	}
	return (1);
}

static int	parser(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		j;

	a->stack = malloc(sizeof(int) * (ac - 1));
	b->stack = malloc(sizeof(int) * (ac - 1));
	if (!(a->stack) || !(b->stack))
	{
		free(a->stack);
		return (0);
	}
	b->size = 0;
	a->size = ac - 1;
	i = 0;
	while (++i < a->size + 1)
		a->stack[i - 1] = ft_atoi(av[i]);
	i = -1;
	while (++i < a->size - 1)
	{
		j = i;
		while (++j < a->size)
			if (a->stack[i] == a->stack[j])
				return (0);
	}
	return (1);
}

char	**refined_av(int ac, char **av)
{
	char	**av_refined;
	int		i;

	if (ac == 2)
	{
		av_refined = ft_split(av[1], ' ');
		if (!av_refined)
			return (0);
	}
	else
	{
		av_refined = malloc(sizeof(char *) * ac);
		if (!av_refined)
			return (0);
		i = -1;
		while (++i < ac - 1)
			av_refined[i] = av[i + 1];
		av_refined[ac - 1] = NULL;
	}
	return (av_refined);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**av_refined;

	if (ac == 1)
		return (0);
	av_refined = refined_av(ac, av);
	if (!av_refined)
		return (write(STDOUT_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
	a.stack = 0;
	b.stack = 0;
	if ((!check_for_phony(av_refined) || !parser(ac, av, &a, &b)) && \
			free_all(&a, &b, av_refined))
		return (write(STDOUT_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
	checker(&a, &b);
	free_all(&a, &b, av_refined);
}
