/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_sort_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:55:54 by llahti            #+#    #+#             */
/*   Updated: 2020/02/25 10:54:11 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_smallest_to_beginning_b(t_stacks *stacks, int smallest)
{
	if (ft_distance(stacks->a, smallest) <= stacks->a_len / 2)
	{

		ft_rotate_stack_to(smallest, 'a', stacks);
	}
	else
		ft_reverse_rotate_stack_to(smallest, 'a', stacks);
	ft_pspush(stacks, 'b');
	return (ft_find_smallest_since(stacks->a, stacks->a_len, smallest));
}

int		ft_is_basically_sorted(t_stacks *stacks, int smallest, int biggest)
{
	t_lst	*temp;
	int		first;

	if (stacks->a->nb == smallest)
		return (ft_list_is_sorted(stacks->a));
	temp = stacks->a;
	first = temp->nb;
	while (temp->next)
	{
		if ((temp->nb == biggest && temp->next->nb == smallest) ||
			(temp->nb < temp->next->nb))
			temp = temp->next;
		else
			return (0);
	}
	if (first != smallest && first < temp->nb)
		return (0);
	while (stacks->a->nb != smallest)
		ft_psrotate(stacks, 'a');
	return (1);
}

int		ft_sort_a(t_stacks *stacks)
{
	int		smallest;
	int		biggest;
	int		smallest_since;
	int		pushed;
	
	pushed = 0;
	smallest = ft_find_smallest(stacks->a, stacks->a_len);
	biggest = ft_find_biggest(stacks->a, stacks->a_len);
	smallest_since = smallest;
	while (!(ft_is_basically_sorted(stacks, smallest_since, biggest)))
	{
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
