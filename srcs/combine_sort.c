/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:58:13 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_combine_sort(t_stacks *stacks)
{
	int     pivot;
	int		a_pivot;
	int     b_pivot;

	pivot = ft_cs_pivot(stacks);
	b_pivot = ft_cs_pivot_under(pivot, stacks);
	a_pivot = ft_cs_split(pivot, b_pivot, stacks);
	ft_sort_a(stacks);
	ft_part_to_a(stacks, pivot, a_pivot);
	ft_part_to_a(stacks, b_pivot, pivot);
	ft_rest_to_a(stacks, b_pivot);
}
