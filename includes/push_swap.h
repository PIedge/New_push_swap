/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:34:53 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:12:52 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "moves.h"

# define ERR_MSG "Error\n"

/*
**	Core
*/
void	setup_b(t_stack *b, t_stack *a, t_moves *mv);
void	move_a(t_stack *a, t_stack *b, t_moves *mv);
void	setup_for_push(t_stack *a, t_stack *b);
int		is_b_ready_for_push(t_stack *b);
int		is_a_ready_for_push(t_stack *a, t_stack *b);
int		new_range(int i, t_stack *c);
int		left_from_range(t_stack *a, int range);
void	find_next(t_stack *a, t_number *n, int range);
void	setup_b(t_stack *b, t_stack *a, t_moves *mv);
void	move_a(t_stack *a, t_stack *b, t_moves *mv);
void	move_stacks_for_push(t_stack *a, t_stack *b, t_moves *a_mv, \
		t_moves *b_mv);
int		not_sorted(t_stack *a);
void	fill_c(t_stack *a, t_stack *c);
int		parser(char **av, t_stack *a, t_stack *b, t_stack *c);
void	should_we_sync(t_moves *a, t_moves *b);
void	how_much_moves(t_stack *a, t_stack *b, t_number *n, t_moves *b_mv);
/*
**	Algos
*/
void	put_a_top(t_stack *a, t_stack *b);
void	setup_for_push(t_stack *a, t_stack *b);
void	how_much_moves(t_stack *a, t_stack *b, t_number *n, t_moves *b_mv);
void	under_three(t_stack *a, t_stack *b);
void	three(t_stack *a, t_stack *b);
void	five(t_stack *a, t_stack *b, t_stack *c);
void	hundreds(t_stack *a, t_stack *b, t_stack *c);
/*
**	Utils
*/
int		return_smallest(int x, int y);
int		get_rev_rot(t_moves *mv);
int		get_rot(t_moves *mv);
void	reverse_t_rot(t_moves *mv);
void	get_big_small(t_stack *s);
int		find_place_cost_in_b(t_stack *s, t_number *n);
void	init_t_number(t_number *n);
void	visual_stacks(t_stack *a, t_stack *b);
int		ft_ceil(double n);
size_t	ft_strlen(char *str);
int		ft_atoi(char *str);

#endif
