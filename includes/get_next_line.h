/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:08:11 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:26:59 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int					get_next_line(int fd, char **line);
int					line_nav_n_search(char *rest, char **line, int *ret_read, \
	int fd);
int					search_end_line(char *s);

size_t				gnl_strlen(char const *s);
void				gnl_memcpy(char *to, char const *from, int max);
char				*gnl_strnjoin(char const *s1, char const *s2, int n);
void				ft_charcpy(char *s, int n, char c);
#endif
