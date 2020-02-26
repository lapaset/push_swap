/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/26 16:01:06 by llahti           ###   ########.fr       */
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

int		ft_find_the_smallest(t_lst *stack)
{
	int		smallest;

	smallest = stack->nb;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nb < smallest)
			smallest = stack->nb;
	}
	return (smallest);
}

int		ft_find_next_smallest(t_lst *stack, int nb)
{
	int		next_smallest;

	while (stack && stack->nb <= nb)
		stack = stack->next;
	if (!stack)
		ft_error();
	next_smallest = stack->nb;
	if (stack->nb == nb + 1)
		return (stack->nb);
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nb == nb + 1)
			return (stack->nb);
		if (stack->nb > nb && stack->nb < next_smallest)
			next_smallest = stack->nb;
	}
	return (next_smallest);
}

int		ft_find_the_biggest(t_lst *stack)
{
	int		biggest;

	biggest = stack->nb;
	while (stack)
	{
		if (stack->nb > biggest)
			biggest = stack->nb;
		stack = stack->next;
	}
	return (biggest);
}

int		ft_find_next_biggest(t_lst *stack, int nb)
{
	int		next_biggest;

	while (stack && stack->nb >= nb)
		stack = stack->next;
	if (!stack)
		ft_error();
	next_biggest = stack->nb;
	if (stack->nb == nb - 1)
		return (stack->nb);
	while (stack->next)
	{
		stack = stack->next;
		if (stack->nb == nb - 1)
			return (stack->nb);
		if (stack->nb > next_biggest && stack->nb < nb)
			next_biggest = stack->nb;		
	}
	return (next_biggest);
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
