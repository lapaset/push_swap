/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/24 17:09:05 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# include "stacks.h"
# include <fcntl.h>

# define WIN_WIDTH 1700
# define WIN_HEIGHT 1000
# define MAX_INSTRUCTIONS 3000
# define MAX_PRINT 500
# define MAX_SPEED 50000

typedef struct 		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	t_stacks		*stacks;
	int				min;
	int				max;
	char			**instructions;
	int				i;
	int				drawn;
	int				column_width;
	int				multiply;
	int				speed;
	int				y_zero;
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

//ft_visualize:
void				ft_visualize(t_stacks *stacks);
void				ft_close(t_mlx *ptrs);

//ft_draw_stack:
void				ft_draw_stack(t_mlx *ptrs, t_lst *stack, int x, char *color);

#endif