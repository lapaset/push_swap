/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:57:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include "mlx.h"
# include <fcntl.h>

# define WIN_WIDTH 1700
# define WIN_HEIGHT 1000

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
}					t_stacks;

typedef struct 		s_ptrs
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_stacks		*stacks;
}					t_ptrs;


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

//do_operations:
void				ft_do_operations(t_stacks *stacks, int visualize);

//ft_visualize:
void				ft_visualize(t_stacks *stacks);

#endif