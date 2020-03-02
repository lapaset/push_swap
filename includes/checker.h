/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/03/02 13:37:56 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# include "stacks.h"
# include <fcntl.h>

# define WIN_WIDTH 1800
# define WIN_HEIGHT 800
# define MAX_MOVES 6000
# define MIN_SPEED 100000

typedef struct 		s_mlx
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

typedef struct 		s_color
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

int					ft_deal_instructions(t_stacks *stacks, t_flags *flags,
					t_mlx *mlx);
char				**ft_instructions(void);
void				ft_free_instructions(char **instructions);
int					ft_instruction_nb(char *input, char **instructions);

void				ft_read_and_do(int fd, t_stacks *stacks, t_flags *flags);
int					ft_read_to_mlx(t_mlx *mlx, t_stacks *stacks);

void				ft_visualize(t_mlx *mlx);

void				ft_draw_stack(t_mlx *ptrs, t_lst *stack, int x, char *color);

void				ft_visualize_moves(t_mlx *mlx, int moves_amount);

int					ft_deal_key(int key, t_mlx *mlx);
void				ft_close(t_mlx *ptrs);

#endif