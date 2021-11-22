/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:01:14 by tmerrien          #+#    #+#             */
/*   Updated: 2021/05/17 16:36:48 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/checker.h"
#include "../includes/colors.h"

void	visual_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->size || i < b->size)
	{
		if (i < a->size)
			printf("%d", (a->stack)[i]);
		else
			printf(" ");
		printf(" ");
		if (i < b->size)
			printf("%d\n", (b->stack)[i]);
		else
			printf(" \n");
		++i;
	}
	printf("_ _\n");
	printf("a b\n");
}
