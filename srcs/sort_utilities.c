/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/20 12:39:17 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_pivot(t_lst *stack, int average, int amount)
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

int		ft_find_smallest(t_lst *stack, int amount)
{
	int		smallest;
	int		i;

	smallest = stack->nb;
	i = 0;
	while (i < amount && stack)
	{
		if (stack->nb < smallest)
			smallest = stack->nb;
		stack = stack->next;
	}
	return (smallest);
}


//do something to imaginary nbrs
int		ft_find_smallest_since(t_lst *stack, int amount, int since)
{
	int		i;
	int		next;

	i = 0;
	while (i < amount && stack && stack->nb < since)
		stack = stack->next;
	next = stack->nb;
	while (i < amount && stack)
	{
		if (stack->nb == since + 1)
			return (since + 1);
		if (stack->nb < next && stack->nb > since)
			next = stack->nb;
		stack = stack->next;
	}
	return (next);
}

int		ft_find_biggest(t_lst *stack, int amount)
{
	int		biggest;
	int		i;

	biggest = stack->nb;
	i = 0;
	while (i < amount && stack)
	{
		if (stack->nb > biggest)
			biggest = stack->nb;
		stack = stack->next;
	}
	return (biggest);
}

int		ft_find_biggest_since(t_lst *stack, int amount, int since)
{
	int		i;
	int		next;

	i = 0;
	while (i < amount && stack && stack->nb > since)
		stack = stack->next;
	next = stack->nb;
	while (i < amount && stack)
	{
		if (stack->nb == since - 1)
			return (since - 1);
		if (stack->nb > next && stack->nb < since)
			next = stack->nb;
		stack = stack->next;
	}
	return (next);
}

int		ft_distance(t_lst *stack, int nb)
{
	int 	distance;

	distance = 0;
	while (stack && stack->nb != nb)
	{
		stack = stack->next;
		distance++;
	}
	return (distance);
}
