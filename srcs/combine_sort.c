/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:32:15 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_combine_sort(t_stacks *stacks, int *arr)
{
	int		pivot;
	int		a_pivot;
	int		b_pivot;

	pivot = ft_pivot_from_arr(arr, stacks->a, stacks->a_len);
	b_pivot = ft_pivot_under(pivot, stacks, arr);
	a_pivot = ft_cs_split(pivot, b_pivot, stacks, arr);
	ft_sort_a(stacks);
	ft_part_to_a(stacks, pivot);
	ft_part_to_a(stacks, b_pivot);
	ft_rest_to_a(stacks);
}
