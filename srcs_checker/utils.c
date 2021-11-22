/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 08:59:25 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 09:00:42 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/moves.h"

int	free_all(t_stack *a, t_stack *b, char **av_refined)
{
	free(a->stack);
	free(b->stack);
	free(av_refined);
	return (1);
}
