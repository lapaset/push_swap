/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:12:08 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:28:24 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "../libft/srcs/libft/libft.h"

typedef struct		s_lst
{
	int				nb;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stacks
{
	t_lst			*a;
	t_lst			*a_end;
	t_lst			*b;
	t_lst			*b_end;
	int				a_len;
	int				b_len;

}					t_stacks;

void				ft_params_to_list(int arg, char **argv, t_stacks *stacks);

t_lst				*ft_new_elem(int nb);
t_lst				*ft_add_elem_to_start(t_lst *stack, t_lst *elem);
t_lst				*ft_add_elem_to_end(t_lst *stack_last, t_lst *elem);

void				ft_swap(t_stacks *stacks, char c);
void				ft_push(t_stacks *stacks, char c);
void				ft_rotate(t_stacks *stacks, char c);
void				ft_reverse_rotate(t_stacks *stacks, char c);

void				ft_print_lst(t_lst *lst);
int					ft_list_is_sorted(t_lst *stack);
void				ft_error(void);
int					ft_atoi_push_swap(const char *str);
void				(**g_ft_operations(void))(t_stacks*, char);

#endif
