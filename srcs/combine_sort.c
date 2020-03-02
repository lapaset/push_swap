/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/03/01 09:52:45 by llahti           ###   ########.fr       */
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
	ft_part_to_a(stacks, pivot);
	ft_part_to_a(stacks, b_pivot);
	ft_rest_to_a(stacks);
	/*ft_printf("a_pivot: %d pivot: %d b_pivot: %d\n", a_pivot, pivot, b_pivot);
	ft_print_lst(stacks->a, a_pivot, pivot, b_pivot);
	ft_printf("stack b: ");
	ft_print_lst(stacks->b, a_pivot, pivot, b_pivot);*/
	
}
