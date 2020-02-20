/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/02/20 13:19:58 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_rotated(int biggest, t_lst *stack, int pivot)
{
	while (stack->nb > pivot && stack)
	{
		if (stack->nb == biggest)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//here could take advantance on knowing the beginning of the lst before rotating
//every time rotated is 0 save the first node to be rotated, put it to null when rotated goes back to 0
void	ft_part_to_a(t_stacks *stacks, int pivot, int biggest)
{
	int		rotated;

	rotated = 0;
	while (rotated != 0 || stacks->b->nb > pivot)
	{
		if (stacks->b->nb != biggest && ft_is_rotated(biggest, stacks->b, pivot))
		{
			rotated -= ft_reverse_rotate_stack_to(biggest, 'b', stacks);
		}
		else if (stacks->b->nb != biggest)
		{
			rotated += ft_rotate_stack_to(biggest, 'b', stacks);
		}
		ft_pspush(stacks, 'a');
		biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
		//ft_printf("%d, %d", biggest, stacks->b_len);
	}
}

void	ft_rest_to_a(t_stacks *stacks, int biggest)
{
	while (stacks->b_len > 2)
	{
		if (ft_distance(stacks->b, biggest) <= stacks->b_len / 2)
			ft_rotate_stack_to(biggest, 'b', stacks);
		else
			ft_reverse_rotate_stack_to(biggest, 'b', stacks);
		ft_pspush(stacks, 'a');
		biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
	}
	if (stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
	ft_pspush(stacks, 'a');
	ft_pspush(stacks, 'a');
}

//maybe separate sort function that picks the most effective sorting method
//could also count the moves required by each

void    ft_sort(t_stacks *stacks)
{
	int     pivot;
	int		a_pivot;
	int     b_pivot;

	pivot = ft_pivot(stacks->a, ft_average(stacks->a, stacks->a_len),
						stacks->a_len);
	b_pivot = ft_pivot_under(stacks->a, ft_average_under(pivot, stacks->a));
	a_pivot = ft_cs_split(pivot, b_pivot, stacks);
	ft_sort_a(stacks);
	ft_part_to_a(stacks, pivot, a_pivot);
	//ft_print_lst(stacks->b);
	//ft_printf("b_pivot: %d pivot: %d\n", b_pivot, pivot);
	//ft_printf("here\n");
	ft_part_to_a(stacks, b_pivot, pivot);
	//ft_printf("b_pivot: %d pivot: %d\n", b_pivot, pivot);
	ft_rest_to_a(stacks, b_pivot);
}

//1210
//844
//620
//829
//716
//677
//669

//check if the node is already at the right place
//keep track on the smallest node
//while looking for the biggest, push all smallest since to b