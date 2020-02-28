/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:42:45 by llahti            #+#    #+#             */
/*   Updated: 2020/02/28 17:07:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap_if_first_is_bigger(t_stacks *stacks, char stack)
{
	if (stack == 'a' && stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (stack == 'b' && stacks->b->nb > stacks->b->next->nb)
		ft_psswap(stacks, 'b');
}

void		ft_quicksort(t_stacks *stacks, int amount)
{
	//amount is the amount of numbers at stack a that are unsorted
	//if amount < 4
	// - sort amount
	// - move on to sorting the possible rest at b
	//else
	// - find the pivot
	// - move smaller than pivot to b and save the amount moved as rest
	// - quicksort the amount left on a
	if (amount < 4)
	{	
		if (amount == 1)
		{
			ft_printf("amount == 1\n");
			return ;
		}
		if (amount == 2)
		{
			ft_swap_if_first_is_bigger(stacks, 'a');
			ft_printf("amount == 2\n");
			return ;
		}
		if (stacks->a_len == 3)
		{
			ft_sort_a_of_three(stacks);
			return ;
		}
		if (stacks->a->nb < stacks->a->next->next->nb &&
			stacks->a->next->nb < stacks->a->next->next->nb)		
			ft_swap_if_first_is_bigger(stacks, 'a');
		else if (stacks->a->nb > stacks->a->next->nb &&
			stacks->a->nb > stacks->a->next->next->nb)
		{
			//321 312
			ft_psswap(stacks, 'a');
			ft_psrotate(stacks, 'a');
			ft_psswap(stacks, 'a');
			ft_psreverse_rotate(stacks, 'a');
			ft_swap_if_first_is_bigger(stacks, 'a');
		}
		else
		{
			//231 132
			ft_psrotate(stacks, 'a');
			ft_psswap(stacks, 'a');
			ft_psreverse_rotate(stacks, 'a');
			ft_swap_if_first_is_bigger(stacks, 'a');
		}
	}
}