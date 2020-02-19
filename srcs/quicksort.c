/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/02/18 14:06:56 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_if_needed(t_stacks *stacks, char c)
{
	if ((c == 'a' && stacks->a && stacks->a->next &&
			stacks->a->nb > stacks->a->next->nb) ||
		(c == 'b' && stacks->b && stacks->b->next &&
		stacks->b->nb < stacks->b->next->nb) ||
		(c == 'c' && stacks->a && stacks->a->next &&
		stacks->b && stacks->b->next &&
		stacks->a->nb > stacks->a->next->nb &&
		stacks->b->nb < stacks->b->next->nb))
		ft_psswap(stacks, c);
	else if (c == 'c' && stacks->a && stacks->a->next &&
			stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (c == 'c' && stacks->b && stacks->b->next &&
			stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
}

void	ft_sort_three(t_stacks *stacks, char c)
{
	ft_swap_if_needed(stacks, c);
	ft_psrotate(stacks, c);
	ft_swap_if_needed(stacks, c);
	ft_psreverse_rotate(stacks, c);
	ft_swap_if_needed(stacks, c);
}

int 	ft_move_from(char from, t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (amount)
	{
		//ft_printf("amount: %d, a->nb: %d\n", amount, stacks->a->nb);
		if (from == 'a' && stacks->a->nb <= pivot)
			ft_pspush(stacks, 'b');
		else if (from == 'a')
		{
			ft_psrotate(stacks, 'a');
			rotated++;
		}
		else if (from == 'b' && stacks->b->nb >= pivot)
			ft_pspush(stacks, 'a');
		else if (from == 'b')
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
			ft_psreverse_rotate(stacks, from);
			i--;
		}
	}
	return (rotated);
}

void	ft_quicksort_b(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	//int		amount_next;
	int 	i;
	int		rotated;

	if (amount <= 3)
	{
		i = amount;
		while (i)
		{
			ft_pspush(stacks, 'a');
			i--;		
		}
		if (amount == 3)
			ft_sort_three(stacks, 'a');
		if (amount == 2)
			ft_swap_if_needed(stacks, 'c');
		return ;
	}
	average = ft_average(stacks->b, amount);
	pivot = ft_pivot(stacks->b, average, amount);
	//ft_printf("amount: %d average: %d pivot: %d\n", amount, average, pivot);
	rotated = ft_move_from('b', stacks, pivot, amount, first);
	ft_quicksort(stacks, amount - rotated, first);
	ft_quicksort_b(stacks, rotated, first);
}

void	ft_quicksort(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_pivot(stacks->a, average, amount);

		amount_next = ft_move_from('a', stacks, pivot, amount, first);
		ft_quicksort(stacks, amount_next, first);

		//ft_print_lst(stacks->a);
		//ft_print_lst(stacks->b);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, first);
	}
	else if (amount == 3)
		ft_sort_three(stacks, 'c');
	else if (amount == 2)
		ft_swap_if_needed(stacks, 'c');
}
