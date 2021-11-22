/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 06:02:28 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 09:00:18 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define NB_CMD 12
# define MAX_LENGTH_CMD 3
# define ERR_MSG "Error\n"

# include "../includes/moves.h"

int					checker(t_stack *a, t_stack *b);
void				visual_stacks(t_stack *a, t_stack *b);
int					search_apply(char *line, t_stack *a, t_stack *b);
int					final(t_stack *a);
int					get_next_order(t_stack *a, t_stack *b);
int					swap_checker(char *line, t_stack *a, t_stack *b);
int					push_checker(char *line, t_stack *a, t_stack *b);
int					rotate_checker(char *line, t_stack *a, t_stack *b);
int					free_all(t_stack *a, t_stack *b, char **av_refined);
#endif
