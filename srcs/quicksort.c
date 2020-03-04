/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:33:19 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_quicksort_b(t_stacks *stacks, int amount, int *arr)
{
	int		pivot;
	int		rotated;

	if (amount <= 3)
	{
		ft_push_three_or_less_to_a(stacks, amount);
		return ;
	}
	pivot = ft_pivot_from_arr(arr, stacks->b, amount);
	rotated = ft_move_from_b(stacks, pivot, amount);
	ft_quicksort(stacks, amount - rotated, 0, arr);
	ft_quicksort_b(stacks, rotated, arr);
}

void		ft_quicksort(t_stacks *stacks, int amount, int first, int *arr)
{
	int		pivot;
	int		amount_next;
	int		rest;

	if (ft_list_is_sorted(stacks->a))
		return ;
	if (amount > 3)
	{
		pivot = ft_pivot_from_arr(arr, stacks->a, amount);
		amount_next = ft_move_from_a(stacks, pivot, amount, first);
		ft_quicksort(stacks, amount_next, first, arr);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, arr);
	}
	else if (amount == 3)
		ft_sort_three_at_a(stacks);
	else if (amount == 2)
		ft_swap_a_if_first_is_bigger(stacks);
}
