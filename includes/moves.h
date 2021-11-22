/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerrien <tmerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:24:00 by tmerrien          #+#    #+#             */
/*   Updated: 2021/11/22 08:29:08 by tmerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# include <stdlib.h>

/*
**	direction 1 = rotate 0 = reverse rotate
*/

typedef enum e_rot
{
	rotate_,
	reverse_rotate,
	both
}					t_rot;

typedef struct s_moves
{
	t_rot			rot;
	int				placed;
	int				nb_rotations;
	int				nb_reverse_rotations;
}					t_moves;

typedef struct s_number
{
	int				number;
	int				index;
	int				cost;
	int				direction;
	t_moves			mv;
}					t_number;

typedef struct s_stack
{
	int				*stack;
	int				size;
	int				small;
	int				big;
	int				done;
}					t_stack;

void				swap(t_stack *manip, t_stack *useless, char *op, int mode);
int					make_swap(t_stack *manip, t_stack *useless, int mode);
void				push(t_stack *from, t_stack *to, char *op);
int					make_push(t_stack *from, t_stack *to);
void				rotate(t_stack *manip, t_stack *useless, char *op, \
	int mode);
int					make_rotate(t_stack *manip, t_stack *useless, int mode);
void				rev_rotate(t_stack *manip, t_stack *useless, char *op, \
	int mode);
int					make_rev_rotate(t_stack *manip, t_stack *useless, int mode);

#endif
