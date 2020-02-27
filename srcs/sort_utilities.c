/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:05:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:59:12 by llahti           ###   ########.fr       */
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

void	ft_push_to_a_and_swap_if_needed(t_stacks *stacks)
{
	if (stacks->b_len == 0)
		return ;
	ft_pspush(stacks, 'a');
	if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
}
