/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:34:22 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:44:43 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_nb_is_in_the_rotated(int biggest, t_lst *stack, int pivot)
{
	while (stack->nb > pivot && stack)
	{
		if (stack->nb == biggest)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int		ft_part_size(t_lst *stack, int pivot)
{
	int size;

	size = 0;
	while (stack && stack->nb > pivot)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static void		ft_move_all_but_two(t_stacks *stacks, int biggest, int pivot,
		int part_size)
{
	int		second_biggest;
	int		is_rotated;

	while (part_size > 2)
	{
		second_biggest = ft_find_next_biggest(stacks->b, biggest);
		is_rotated = ft_nb_is_in_the_rotated(biggest, stacks->b, pivot);
		while (stacks->b->nb != biggest)
		{
			if (stacks->b->nb == second_biggest)
			{
				ft_pspush(stacks, 'a');
				part_size--;
			}
			else if (is_rotated)
				ft_psreverse_rotate(stacks, 'b');
			else
				ft_psrotate(stacks, 'b');
		}
		ft_push_to_a_and_swap_if_needed(stacks);
		part_size--;
		if (part_size > 2)
			biggest = ft_find_next_biggest(stacks->b, biggest);
	}
}

void			ft_rest_to_a(t_stacks *stacks, int biggest)
{
	int		second_biggest;
	int		is_rotated;

	while (stacks->b_len > 2)
	{
		second_biggest = ft_find_next_biggest(stacks->b, biggest);
		is_rotated = ft_is_rotated(stacks, 'b', biggest);
		while (stacks->b->nb != biggest)
		{
			if (stacks->b->nb == second_biggest)
				ft_pspush(stacks, 'a');
			else if (!is_rotated)
				ft_psrotate(stacks, 'b');
			else
				ft_psreverse_rotate(stacks, 'b');
		}
		ft_push_to_a_and_swap_if_needed(stacks);
		if (stacks->b_len > 2)
			biggest = ft_find_next_biggest(stacks->b, biggest);
	}
	ft_pspush(stacks, 'a');
	ft_push_to_a_and_swap_if_needed(stacks);
}

void			ft_part_to_a(t_stacks *stacks, int pivot, int biggest)
{
	int		part_size;

	part_size = ft_part_size(stacks->b, pivot);
	if (part_size > 2)
		ft_move_all_but_two(stacks, biggest, pivot, part_size);
	while (stacks->b_end->nb > pivot)
		ft_psreverse_rotate(stacks, 'b');
	ft_pspush(stacks, 'a');
	if (stacks->b && stacks->b->nb > pivot)
		ft_push_to_a_and_swap_if_needed(stacks);
}
