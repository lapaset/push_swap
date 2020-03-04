/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:07:08 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 11:36:47 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_the_smallest_in(t_lst *stack, int amount)
{
	int		smallest;
	int		i;

	smallest = stack->nb;
	i = 1;
	while (stack->next && i < amount)
	{
		stack = stack->next;
		if (stack->nb < smallest)
			smallest = stack->nb;
		i++;
	}
	return (smallest);
}

int			ft_pivot_from_arr(int *arr, t_lst *stack, int amount)
{
	int		smallest;
	int		smallest_i;

	smallest = ft_find_the_smallest_in(stack, amount);
	smallest_i = 0;
	while (arr[smallest_i] != smallest)
		smallest_i++;
	return (arr[smallest_i + amount / 2]);
}

static int	ft_count_values_under(int limit, t_lst *stack)
{
	int		count;

	count = 0;
	while (stack)
	{
		if (stack->nb < limit)
			count++;
		stack = stack->next;
	}
	return (count);
}

int			ft_pivot_under(int limit, t_stacks *stacks, int *arr)
{
	return (ft_pivot_from_arr(arr, stacks->a,
								ft_count_values_under(limit, stacks->a)));
}
