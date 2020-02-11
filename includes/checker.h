/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/11 17:21:11 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

# define WIN_WIDTH 1700
# define WIN_HEIGHT 1000
# define MAX_INSTRUCTIONS 1000
# define MAX_PRINT 500

typedef struct 		s_lst
{
	int				nb;
	struct s_lst 	*next;
}					t_lst;

typedef struct		s_stacks
{
	t_lst			*a;
	t_lst			*a_end;
	t_lst			*b;
	t_lst			*b_end;
	int				size;
}					t_stacks;

typedef struct 		s_ptrs
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_ptr;
	t_stacks		*stacks;
}					t_ptrs;

typedef struct 		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

//CHECKER:
//utilities:
void				ft_print_lst(t_lst *lst);
int					ft_list_is_sorted(t_lst *stack);
void				ft_print_result(t_stacks *stacks);
void				ft_error(void);
int					ft_atoi_checker(const char *str);

//make_list:
void				ft_params_to_list(int arg, char **argv, t_stacks *stacks);
t_lst				*ft_add_elem_to_start(t_lst *stack, t_lst *elem);
t_lst				*ft_add_elem_to_end(t_lst *stack_last, t_lst *elem);

//operations:
void				ft_swap(t_stacks *stacks, char c);
void				ft_push(t_stacks *stacks, char c);
void				ft_rotate(t_stacks *stacks, char c);
void				ft_reverse_rotate(t_stacks *stacks, char c);
void				(**ft_operations(void))(t_stacks*, char);

//do_operations:
void				ft_deal_instructions(t_stacks *stacks);
char				**ft_instructions(void);
void				ft_free_instructions(char **instructions);

//ft_visualize:
void				ft_visualize(t_stacks *stacks);
void				ft_close(t_ptrs *ptrs);

//ft_draw_stack:
void				ft_draw_stack(t_ptrs *ptrs, t_lst *stack, int x, char *color);

#endif