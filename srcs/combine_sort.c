/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/02/21 16:50:24 by llahti           ###   ########.fr       */
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

void	ft_push_to_a_and_swap_if_needed(t_stacks *stacks)
{
	ft_pspush(stacks, 'a');
	if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
}

int		ft_rotate_stack_to_biggest(t_stacks *stacks, int pivot, int biggest, int second_biggest)
{
	int		rotated;
	int		is_rotated;

	rotated = 0;
	is_rotated = ft_is_rotated(biggest, stacks->b, pivot);	
	while (stacks->b->nb != biggest)
	{
		if (stacks->b->nb == second_biggest)
			ft_pspush(stacks, 'a');
		else if (is_rotated)
		{
			ft_psreverse_rotate(stacks, 'b');
			rotated--;
		}
		else
		{
			ft_psrotate(stacks, 'b');
			rotated++;
		}
	}
	return (rotated);
}

//here could take advantance on knowing the beginning of the lst before rotating
//every time rotated is 0 save the first node to be rotated, put it to null when rotated goes back to 0
void	ft_part_to_a(t_stacks *stacks, int pivot, int biggest)
{
	int		rotated;
	int		second_biggest;

	rotated = 0;
	second_biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
	while (rotated != 0 || stacks->b->nb > pivot)
	{
		rotated += ft_rotate_stack_to_biggest(stacks, pivot, biggest, second_biggest);
		ft_push_to_a_and_swap_if_needed(stacks);
		biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
		second_biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
	}
}

void	ft_rest_to_a(t_stacks *stacks, int biggest)
{
	int		second_biggest;
	int		rotate;

	second_biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
	while (stacks->b_len > 2)
	{
		if (ft_distance(stacks->b, biggest) <= stacks->b_len / 2)
			rotate = 1;
		else
			rotate = 0;
		while (stacks->b->nb != biggest)
		{
			if (stacks->b->nb == second_biggest)
				ft_pspush(stacks, 'a');
			else if (rotate)
				ft_psrotate(stacks, 'b');
			else
				ft_psreverse_rotate(stacks, 'b');
		}
		ft_push_to_a_and_swap_if_needed(stacks);
		biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
		second_biggest = ft_find_biggest_since(stacks->b, stacks->b_len, biggest);
	}
	ft_pspush(stacks, 'a');
	ft_push_to_a_and_swap_if_needed(stacks);
}

void    ft_sort(t_stacks *stacks)
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

//make more efficient sort for those small lists
//visualizer to work