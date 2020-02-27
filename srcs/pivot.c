/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:15:33 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:52:37 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_ordernb(int ordernb, t_stacks *stacks)
{
	int		smallest;
	int		i;

	i = 1;
	smallest = ft_find_the_smallest(stacks->a);
	while (i < ordernb)
	{
		smallest = ft_find_next_smallest(stacks->a, smallest);
		i++;
	}
	return (smallest);
}

int			ft_cs_pivot(t_stacks *stacks)
{
	return (ft_find_ordernb(stacks->a_len / 2 + 1, stacks));
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

int			ft_cs_pivot_under(int limit, t_stacks *stacks)
{
	return (ft_find_ordernb(ft_count_values_under(limit, stacks->a) / 2 + 1,
			stacks));
}
