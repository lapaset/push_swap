/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:53:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 09:57:34 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/srcs/libft/libft.h"
# include "stacks.h"

//quicksort:
void		ft_quicksort(t_stacks *stacks, int amount, int first);

//quicksort2
void	    ft_quicksort2(t_stacks *stacks, int amount);

//combine_sort:
void        ft_combine_sort(t_stacks *stacks);
void	    ft_rest_to_a(t_stacks *stacks, int biggest);

//cs_sort_a:
int		    ft_sort_a(t_stacks *stacks);
int		    ft_is_basically_sorted(t_stacks *stacks, int smallest, int biggest);

//cs_split:
int			ft_cs_split(int pivot, int b_pivot, t_stacks *stacks);
void        ft_a_split(t_stacks *stacks, int a_pivot);

//cs_utilities:
int	        ft_average_under(int pivot, t_lst *lst);
int         ft_pivot_under(t_lst *lst, int average);

//pivot:
int         ft_cs_pivot(t_stacks *stacks);
int         ft_cs_pivot_under(int limit, t_stacks *stacks);

//sort_utilities:
int		    ft_average(t_lst *lst, int amount);
int		    ft_find_next_smallest(t_lst *stack, int nb);
int		    ft_find_next_biggest(t_lst *stack, int nb);
int		    ft_find_the_smallest(t_lst *stack);
int		    ft_find_the_biggest(t_lst *stack);
int		    ft_is_rotated(t_stacks *stacks, char stack, int nb);

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

//sort:
void	    ft_sort(t_stacks *stacks, int amount);
void	    ft_sort_a_of_three(t_stacks *stacks);