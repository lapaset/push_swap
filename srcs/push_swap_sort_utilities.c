/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utilities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:32:46 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 14:05:39 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a_if_first_is_bigger(t_stacks *stacks)
{
	if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
}

void	ft_push_to_a_and_swap_if_needed(t_stacks *stacks)
{
	if (stacks->b_len == 0)
		return ;
	ft_pspush(stacks, 'a');
	ft_swap_a_if_first_is_bigger(stacks);
}

void	ft_push_amount_to(t_stacks *stacks, char stack, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		ft_pspush(stacks, stack);
		i++;
	}
}

void	ft_push_biggest_of_three_to_a(t_stacks *stacks)
{
	if (stacks->b->nb < stacks->b->next->nb &&
		stacks->b->next->nb < stacks->b->next->next->nb)
	{
		ft_psrotate(stacks, 'b');
		ft_psswap(stacks, 'b');
		ft_pspush(stacks, 'a');
	}
	if (stacks->b->nb > stacks->b->next->nb &&
		stacks->b->nb > stacks->b->next->next->nb)
		ft_pspush(stacks, 'a');
	else if (stacks->b->next->nb > stacks->b->nb &&
			(stacks->b->next->nb > stacks->b->next->next->nb))
	{
		ft_psswap(stacks, 'b');
		ft_pspush(stacks, 'a');
	}
	else
	{
		ft_psrotate(stacks, 'b');
		ft_psswap(stacks, 'b');
		ft_pspush(stacks, 'a');
		ft_psreverse_rotate(stacks, 'b');
	}
}
