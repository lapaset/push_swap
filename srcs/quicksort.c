/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 20:49:13 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_the_smallest_in(t_lst *stack, int amount)
{
	int		smallest;
	int		i;

	smallest = stack->nb;
	i = 0;
	while (stack->next && i < amount)
	{
		stack = stack->next;
		if (stack->nb < smallest)
			smallest = stack->nb;
		i++;
	}
	return (smallest);
}

int		ft_find_next_smallest_in(t_lst *stack, int nb, int amount)
{
	int		next_smallest;
	int		i;

	i = 0;
	while (stack && stack->nb <= nb && i < amount)
	{
		stack = stack->next;
		i++;
	}
	if (!stack || i == amount)
		ft_error();
	if (stack->nb == nb + 1)
		return (stack->nb);
	next_smallest = stack->nb;
	while (stack->next && i < amount)
	{
		stack = stack->next;
		if (stack->nb == nb + 1)
			return (stack->nb);
		if (stack->nb > nb && stack->nb < next_smallest)
			next_smallest = stack->nb;
		i++;
	}
	return (next_smallest);
}

static int	ft_find_ordernb(int ordernb, t_lst *stack, int amount)
{
	int		smallest;
	int		i;

	i = 1;
	smallest = ft_find_the_smallest_in(stack, amount);
	while (i < ordernb)
	{
		smallest = ft_find_next_smallest_in(stack, smallest, amount);
		i++;
	}
	return (smallest);
}

int			ft_qs_pivot_new(t_lst *stack, int amount)
{
	//if (amount > 4 && amount % 2 == 0)
	//	return (ft_find_ordernb(amount / 2, stack, amount));
	return (ft_find_ordernb(amount / 2 + 1, stack, amount));
}

int 	ft_qs_pivot(t_lst *stack, int average, int amount)
{
	int		pivot;
	int		i;

	pivot = stack->nb;
	i = 0;
	while (i < amount && stack)
	{
		if (stack->nb == average)
			return (average);
		if (ft_abs(stack->nb - average) < ft_abs(pivot - average))
			pivot = stack->nb;
		stack = stack->next;
		i++;
	}
	return (pivot);
}

int		ft_rest_are_bigger(t_lst *stack, int amount, int pivot)
{
	while (amount)
	{
		if (stack->nb <= pivot)
			return (0);
		stack = stack->next;
		amount--;
	}
	return (1);
}

int 	ft_move_from_a(t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (!ft_rest_are_bigger(stacks->a, amount, pivot) && amount)
	{
		if (stacks->a->nb <= pivot)
			ft_pspush(stacks, 'b');
		else
		{
			ft_psrotate(stacks, 'a');
			rotated++;
		}
		amount--;
	}
	if (!first)
	{
		i = rotated;
		while (i)
		{
			ft_psreverse_rotate(stacks, 'a');
			i--;
		}
	}
	return (rotated + amount);
}

int		ft_rest_are_smaller(t_lst *stack, int amount, int pivot)
{
	while (amount)
	{
		if (stack->nb >= pivot)
			return (0);
		stack = stack->next;
		amount--;
	}
	return (1);
}

int 	ft_move_from_b(t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (!ft_rest_are_smaller(stacks->b, amount, pivot) && amount)
	{
		if (stacks->b->nb >= pivot)
			ft_pspush(stacks, 'a');
		else
		{
			ft_psrotate(stacks, 'b');
			rotated++;
		}
		amount--;
	}
	if (!first)
	{
		i = rotated;
		while (i)
		{
			ft_psreverse_rotate(stacks, 'b');
			i--;
		}
	}
	return (rotated + amount);
}

//pivot from array:
//[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
//amount = 5
//find the smallest from arr
//pivot is arr[smallest_i + amount / 2]

int		ft_pivot_from_arr(int *arr, t_lst *stack, int amount)
{
	int		smallest;
	int		smallest_i;

	smallest = ft_find_the_smallest_in(stack, amount);
	smallest_i = 0;
	while (arr[smallest_i] != smallest)
		smallest_i++;
	return (arr[smallest_i + amount / 2]);
}

void	ft_quicksort_b(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		rotated;

	if (amount <= 3)
	{
		ft_push_three_or_less_to_a(stacks, amount);
		return ;
	}
	average = ft_average(stacks->b, amount);
	pivot = ft_qs_pivot(stacks->b, average, amount);
	rotated = ft_move_from_b(stacks, pivot, amount, first);
	ft_quicksort(stacks, amount - rotated, first);
	ft_quicksort_b(stacks, rotated, first);
}

void	ft_quicksort(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (ft_list_is_sorted(stacks->a) && stacks->b_len == 0)
		return ;
	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_qs_pivot(stacks->a, average, amount);
		amount_next = ft_move_from_a(stacks, pivot, amount, first);
		ft_quicksort(stacks, amount_next, first);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, first);
	}
	else if (amount == 3)
		ft_sort_three_at_a(stacks);
	else if (amount == 2)
		ft_swap_a_if_first_is_bigger(stacks);
}
