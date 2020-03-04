/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort_sort_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:55:54 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 17:22:29 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_smallest_to_beginning_b(t_stacks *stacks, int smallest)
{
	if (!ft_is_rotated(stacks, 'a', smallest))
		ft_rotate_stack_to(smallest, 'a', stacks);
	else
		ft_reverse_rotate_stack_to(smallest, 'a', stacks);
	ft_pspush(stacks, 'b');
	return (ft_find_next_smallest(stacks->a, smallest));
}

int		ft_sort_a(t_stacks *stacks)
{
	int		smallest;
	int		biggest;
	int		smallest_since;
	int		pushed;

	pushed = 0;
	smallest = ft_find_the_smallest(stacks->a);
	biggest = ft_find_the_biggest(stacks->a);
	smallest_since = smallest;
	while (!(ft_is_basically_sorted(stacks, smallest_since, biggest)))
	{
		if (stacks->a_len == 3)
		{
			ft_sort_a_of_three(stacks);
			break ;
		}
		smallest_since =
			ft_smallest_to_beginning_b(stacks, smallest_since);
		pushed++;
	}
	while (pushed)
	{
		ft_pspush(stacks, 'a');
		pushed--;
	}
	return (smallest);
}
