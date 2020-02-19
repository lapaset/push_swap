/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:53:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/19 11:05:36 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/srcs/libft/libft.h"
# include "stacks.h"

//quicksort:
void		ft_quicksort(t_stacks *stacks, int amount, int first);

//quicksort2
void	    ft_quicksort2(t_stacks *stacks, int amount);

//combine_sort:
void        ft_sort(t_stacks *stacks, int amount);

//cs_sort_stack_a:
int		    ft_sort_stack_a(t_stacks *stacks, int a_amount);

//sort_utilities:
int		    ft_average(t_lst *lst, int amount);
int 	    ft_pivot(t_lst *lst, int average, int amount);
int		    ft_find_smallest_since(t_lst *stack, int amount, int smallest);
int		    ft_find_smallest(t_lst *stack, int amount);
int		    ft_find_biggest_since(t_lst *stack, int amount, int biggest);
int		    ft_find_biggest(t_lst *stack, int amount);
int		    ft_distance(t_lst *stack, int nb);

//sort_utilities2:
int	        ft_reverse_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int	        ft_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int	        ft_reverse_rotate_stack_end_to(int nb, char stack, t_stacks *stacks);
int	        ft_rotate_stack_end_to(int nb, char stack, t_stacks *stacks);

//ps_operations:
void		ft_psswap(t_stacks *stacks, char c);
void		ft_pspush(t_stacks *stacks, char c);
void		ft_psrotate(t_stacks *stacks, char c);
void		ft_psreverse_rotate(t_stacks *stacks, char c);
