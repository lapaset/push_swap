/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/26 09:07:37 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# include "stacks.h"
# include <fcntl.h>

# define WIN_WIDTH 1300
# define WIN_HEIGHT 800
# define MAX_MOVES 3000
# define MAX_PRINT 500
# define MIN_SPEED 50000

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
	int				i;
	int				drawn;
	int				column_width;
	int				multiply;
	int				speed;
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

//do_operations:
void				ft_deal_instructions(t_stacks *stacks);
char				**ft_instructions(void);
void				ft_free_instructions(char **instructions);

//visualize:
void				ft_visualize(t_stacks *stacks);
void				ft_close(t_mlx *ptrs);

//draw_stack:
void				ft_draw_stack(t_mlx *ptrs, t_lst *stack, int x, char *color);

//animate:
void				ft_show_moves(t_mlx *mlx, int moves_amount);

//key_events:
int					ft_deal_key(int key, t_mlx *mlx);

#endif