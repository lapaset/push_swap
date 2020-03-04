/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_move_from.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:08:53 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:35:41 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rest_are_bigger(t_lst *stack, int amount, int pivot)
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

int			ft_move_from_a(t_stacks *stacks, int pivot, int amount, int first)
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

static int	ft_rest_are_smaller(t_lst *stack, int amount, int pivot)
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

int			ft_move_from_b(t_stacks *stacks, int pivot, int amount)
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
	i = rotated;
	while (i)
	{
		ft_psreverse_rotate(stacks, 'b');
		i--;
	}
	return (rotated + amount);
}
