/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:25 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 17:22:34 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_average(t_lst *stack, int amount)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < amount && stack)
	{
		sum += stack->nb;
		stack = stack->next;
		i++;
	}
	return (sum / amount);
}

int		ft_is_rotated(t_stacks *stacks, char stack, int nb)
{
	int 	distance;
	t_lst	*temp;

	distance = 0;
	if (stack != 'a' && stack != 'b')
		ft_error();
	if (stack == 'a')
		temp = stacks->a;
	else
		temp = stacks->b;
	while (temp && temp->nb != nb)
	{
		temp = temp->next;
		distance++;
	}
	if (stack == 'a')
		return (distance > stacks->a_len / 2);
	return (distance > stacks->b_len / 2);
}

int		ft_is_basically_sorted(t_stacks *stacks, int smallest, int biggest)
{
	t_lst	*temp;
	int		first;

	if (stacks->a->nb == smallest)
		return (ft_list_is_sorted(stacks->a));
	temp = stacks->a;
	first = temp->nb;
	while (temp->next)
	{
		if ((temp->nb == biggest && temp->next->nb == smallest) ||
			(temp->nb < temp->next->nb))
			temp = temp->next;
		else
			return (0);
	}
	if (first != smallest && first < temp->nb)
		return (0);
	if (!ft_is_rotated(stacks, 'a', smallest))
		ft_rotate_stack_to(smallest, 'a', stacks);
	else
		ft_reverse_rotate_stack_to(smallest, 'a', stacks);
	return (1);
}
