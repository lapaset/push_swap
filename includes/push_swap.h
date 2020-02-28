/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:53:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/28 17:08:35 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/srcs/libft/libft.h"
# include "stacks.h"

//combine_sort:
void        ft_combine_sort(t_stacks *stacks);
void	    ft_push_to_a_and_swap_if_needed(t_stacks *stacks);

//tsek sort_a:
int		    ft_sort_a(t_stacks *stacks);
int		    ft_is_basically_sorted(t_stacks *stacks, int smallest, int biggest);

//tsek split:
int			ft_cs_split(int pivot, int b_pivot, t_stacks *stacks);
void        ft_a_split(t_stacks *stacks, int a_pivot);

//tsek pivot:
int         ft_cs_pivot(t_stacks *stacks);
int         ft_cs_pivot_under(int limit, t_stacks *stacks);

//sort_utilities:
int		    ft_average(t_lst *lst, int amount);
int		    ft_is_rotated(t_stacks *stacks, char stack, int nb);
void        ft_push_to_a_and_swap_if_needed(t_stacks *stacks);

//rotate_to:
int	        ft_reverse_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int	        ft_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int	        ft_reverse_rotate_stack_end_to(int nb, char stack, t_stacks *stacks);
int	        ft_rotate_stack_end_to(int nb, char stack, t_stacks *stacks);

//tsek ps_operations:
void		ft_psswap(t_stacks *stacks, char c);
void		ft_pspush(t_stacks *stacks, char c);
void		ft_psrotate(t_stacks *stacks, char c);
void		ft_psreverse_rotate(t_stacks *stacks, char c);

//tsek sort:
void	    ft_sort(t_stacks *stacks, int amount);
void	    ft_sort_a_of_three(t_stacks *stacks);

//tsek part_to_a:
void	    ft_part_to_a(t_stacks *stacks, int pivot, int biggest);
void	    ft_rest_to_a(t_stacks *stacks, int biggest);

//find_smallest_biggest:
int		    ft_find_next_smallest(t_lst *stack, int nb);
int		    ft_find_next_biggest(t_lst *stack, int nb);
int		    ft_find_the_smallest(t_lst *stack);
int		    ft_find_the_biggest(t_lst *stack);

//quicksort:
void	    ft_quicksort(t_stacks *stacks, int amount, int first);