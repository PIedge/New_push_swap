/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:35:18 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:35:27 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str && ++i)
		++str;
	return (i);
}

void	ft_reverse_str(char *str)
{
	char	c;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < (len / 2))
	{
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		++i;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		exp;
	int		neg;

	ret = malloc(sizeof(char) * ((sizeof(INT_MAX) / sizeof(int) + 2)));
	i = 0;
	neg = 0;
	exp = 10;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (n)
	{
		ret[i] = (n % exp) + 48;
		n /= 10;
		++i;
	}
	if (neg)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_reverse_str(ret);
	return (ret);
}
