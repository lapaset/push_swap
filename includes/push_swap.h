/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:53:53 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 14:11:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stacks.h"

void		ft_part_to_a(t_stacks *stacks, int pivot);
void		ft_rest_to_a(t_stacks *stacks);

void		ft_sort_a(t_stacks *stacks);

int			ft_cs_split(int pivot, int b_pivot, t_stacks *stacks, int *arr);
void		ft_a_split(t_stacks *stacks, int a_pivot);

void		ft_combine_sort(t_stacks *stacks, int *arr);

void		ft_psswap(t_stacks *stacks, char c);
void		ft_pspush(t_stacks *stacks, char c);
void		ft_psrotate(t_stacks *stacks, char c);
void		ft_psreverse_rotate(t_stacks *stacks, char c);

int			ft_pivot_from_arr(int *arr, t_lst *stack, int amount);
int			ft_pivot_under(int limit, t_stacks *stacks, int *arr);

int			ft_reverse_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int			ft_rotate_stack_to(int nb, char stack, t_stacks *stacks);
int			ft_reverse_rotate_stack_end_to(int nb, char stack,
			t_stacks *stacks);
int			ft_rotate_stack_end_to(int nb, char stack, t_stacks *stacks);

int			ft_find_next_smallest(t_lst *stack, int nb);
int			ft_find_next_biggest(t_lst *stack, int nb);
int			ft_find_the_smallest(t_lst *stack);
int			ft_find_the_biggest(t_lst *stack);

void		ft_sort_a_of_three(t_stacks *stacks);
void		ft_sort_three_at_a(t_stacks *stacks);
void		ft_push_three_or_less_to_a(t_stacks *stacks, int amount);

void		ft_swap_a_if_first_is_bigger(t_stacks *stacks);
void		ft_push_to_a_and_swap_if_needed(t_stacks *stacks);
void		ft_push_amount_to(t_stacks *stacks, char stack, int amount);
void		ft_push_biggest_of_three_to_a(t_stacks *stacks);

int			ft_is_rotated(t_stacks *stacks, char stack, int nb);
int			ft_is_basically_sorted(t_stacks *stacks, int smallest, int biggest);

int			ft_move_from_a(t_stacks *stacks, int pivot, int amount, int first);
int			ft_move_from_b(t_stacks *stacks, int pivot, int amount);

void		ft_quicksort(t_stacks *stacks, int amount, int first, int *arr);

void		ft_small_sort(t_stacks *stacks, int *arr);

#endif
