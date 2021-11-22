/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:25:44 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:35:00 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	test;
	size_t	i;

	i = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	sub[i] = 0;
	if (!s)
		return (sub);
	test = ft_strlen((char *)s);
	if (test < start)
		return (sub);
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		++i;
	}
	sub[i] = 0;
	return (sub);
}
