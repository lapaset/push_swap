/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilities2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 09:23:18 by llahti            #+#    #+#             */
/*   Updated: 2020/02/20 13:01:54 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_rotate_stack_to(int nb, char stack, t_stacks *stacks)
{
	int count;

	count = 0;
	if (stack == 'a')
	{
		while (stacks->a->nb != nb)
		{

			ft_psrotate(stacks, 'a');
			count++;
		}
	}
	if (stack == 'b')
	{
		while (stacks->b->nb != nb)
		{
			ft_psrotate(stacks, 'b');
			count++;
		}
	}
	return (count);
}

int		ft_reverse_rotate_stack_to(int nb, char stack, t_stacks *stacks)
{
	int count;

	count = 0;
	if (stack == 'a')
	{
		while (stacks->a->nb != nb)
		{
			ft_psreverse_rotate(stacks, 'a');
			count++;
		}
	}
	if (stack == 'b')
	{
		while (stacks->b->nb != nb)
		{
			ft_psreverse_rotate(stacks, 'b');
			count++;
		}
	}
	return (count);
}

int		ft_rotate_stack_end_to(int nb, char stack, t_stacks *stacks)
{
	int count;

	count = 0;
	if (stack == 'a')
	{
		while (stacks->a_end->nb != nb)
		{
			ft_psrotate(stacks, 'a');
			count++;
		}
	}
	if (stack == 'b')
	{
		while (stacks->b_end->nb != nb)
		{
			ft_psrotate(stacks, 'b');
			count++;
		}
	}
	return (count);
}

int		ft_reverse_rotate_stack_end_to(int nb, char stack, t_stacks *stacks)
{
	int count;

	count = 0;
	if (stack == 'a')
	{
		while (stacks->a_end->nb != nb)
		{
			ft_psreverse_rotate(stacks, 'a');
			count++;
		}
	}
	if (stack == 'b')
	{
		while (stacks->b_end->nb != nb)
		{
			ft_psreverse_rotate(stacks, 'b');
			count++;
		}
	}
	return (count);
}