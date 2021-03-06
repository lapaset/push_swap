/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:24:22 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "mlx.h"
# include "stacks.h"
# include <fcntl.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 900
# define MAX_MOVES 6000
# define MIN_SPEED 100000
# define STACK_A_COLOR "5500FF"
# define STACK_B_COLOR "00FFFF"

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	t_stacks		*stacks;
	int				min;
	int				max;
	char			**moves;
	int				moves_amount;
	int				i;
	int				drawn;
	int				speed;
	int				column_width;
	int				multiply;
	int				y_zero;
	void			(**operations)(t_stacks*, char);
	char			**instructions;
}					t_mlx;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_flags
{
	int				v;
	int				e;
	int				d;
}					t_flags;

void				ft_deal_instructions(t_stacks *stacks, t_flags *flags,
					t_mlx *mlx);
char				**ft_instructions(void);
void				ft_free_instructions(char **instructions);
int					ft_instruction_nb(char *input, char **instructions);

void				ft_read_and_do(int fd, t_stacks *stacks, t_flags *flags);
void				ft_read_to_mlx(t_mlx *mlx, t_stacks *stacks, t_flags
					*flags);

void				ft_visualize(t_mlx *mlx);

void				ft_draw_stack(t_mlx *ptrs, t_lst *stack, int x,
					char *color);

void				ft_visualize_moves(t_mlx *mlx, int moves_amount);

int					ft_deal_key(int key, t_mlx *mlx);
void				ft_close(t_mlx *ptrs);

int					ft_is_checker_flag(char *argv);
int					ft_add_checker_flags(int arg, char **argv, t_flags *flags);
void				ft_print_result(t_stacks *stacks, int d);
void				ft_copy_stacks_to_mlx(t_mlx *mlx, t_stacks *stacks);

#endif
