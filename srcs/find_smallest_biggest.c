/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_smallest_biggest.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:10 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:57:07 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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