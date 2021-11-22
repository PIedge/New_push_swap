/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:17 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 11:53:48 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "../includes/push_swap.h"
#include "../includes/moves.h"
#include "../includes/utils.h"

// #include <stdio.h>

int	free_all(t_stack *a, t_stack *b, t_stack *c, char **av_refined)
{
	free(a->stack);
	free(b->stack);
	free(c->stack);
	ft_free_dtab(av_refined);
	return (1);
}

void	push_swap(t_stack *a, t_stack *b, t_stack *c)
{
	if (a->size < 3)
		under_three(a, b);
	else if (a->size == 3)
		three(a, b);
	else if (a->size <= 5)
		five(a, b, c);
	else if (a->size > 5)
		hundreds(a, b, c);
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
			av_refined[i] = ft_substr(av[i + 1], 0, ft_strlen(av[i + 1]));
		av_refined[ac - 1] = NULL;
	}
	return (av_refined);
}

int	main(int ac, char **av)
{
	char	**av_refined;
	t_stack	a;
	t_stack	b;
	t_stack	c;

	a.stack = 0;
	b.stack = 0;
	c.stack = 0;
	if (ac == 1)
		return (write(STDOUT_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
	av_refined = refined_av(ac, av);
	if (!av_refined)
		return (write(STDOUT_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
	if (!parser(av_refined, &a, &b, &c))
	{
		free_all(&a, &b, &c, av_refined);
		return (write(STDOUT_FILENO, ERR_MSG, ft_strlen(ERR_MSG)));
	}
	push_swap(&a, &b, &c);
	free_all(&a, &b, &c, av_refined);
}
