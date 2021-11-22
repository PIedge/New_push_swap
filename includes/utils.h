/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 07:29:18 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 11:29:32 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_abs(int x);
void	ft_free_dtab(char **tab);
#endif