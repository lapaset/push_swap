/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utilities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:32:46 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 17:39:11 by llahti           ###   ########.fr       */
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
