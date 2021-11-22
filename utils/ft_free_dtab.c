/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:57:39 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 12:28:10 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_dtab(char **tab, int mode)
{
	int	y;

	y = 0;
	while (tab[y])
		free(tab[y++]);
	if (mode)
		free(tab);
}
