/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:15:33 by llahti            #+#    #+#             */
/*   Updated: 2020/02/21 16:42:40 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_find_this_smallest(int th, t_stacks *stacks)
{
	int     smallest;
	int     i;

	i = 1;
	smallest = ft_find_smallest(stacks->a, stacks->a_len);
	while (i < th)
	{
		smallest = ft_find_smallest_since(stacks->a, stacks->a_len, smallest);
		i++;
	}
	return (smallest);
}

int     ft_cs_pivot(t_stacks *stacks)
{
	return (ft_find_this_smallest(stacks->a_len / 2 + 1, stacks));
}

int     ft_count_values_under(int limit, t_lst *stack)
{
	int     count;

	count = 0;
	while (stack)
	{
		if (stack->nb < limit)
			count++;
		stack = stack->next;
	}
	return (count);
}

int     ft_cs_pivot_under(int limit, t_stacks *stacks)
{
	return (ft_find_this_smallest(ft_count_values_under(limit, stacks->a) / 2 + 1, stacks));
}
