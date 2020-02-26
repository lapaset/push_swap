/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:23:37 by llahti            #+#    #+#             */
/*   Updated: 2020/02/26 16:01:22 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stacks *stacks)
{
	(void)stacks;
	//132 231 213 321 312
}

void	ft_sort(t_stacks *stacks, int amount)
{
	if (ft_is_basically_sorted(stacks, ft_find_the_smallest(stacks->a), ft_find_the_biggest(stacks->a)))
		return ;
	// upper covers sorting two and sorting three when 312
	if (amount > 0)
		ft_combine_sort(stacks);
}
