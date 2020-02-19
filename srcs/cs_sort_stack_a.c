/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_sort_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 10:55:54 by llahti            #+#    #+#             */
/*   Updated: 2020/02/19 11:02:55 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smallest_to_the_biggest(t_stacks *stacks, int smallest, int biggest,
									int a_amount)
{
	if (ft_distance(stacks->a, smallest) <= a_amount / 2)
		ft_rotate_stack_to(smallest, 'a', stacks);
	else
		ft_reverse_rotate_stack_to(smallest, 'a', stacks);
	ft_pspush(stacks, 'b');
	if (a_amount - ft_distance(stacks->a, biggest) <= a_amount / 2)
		ft_reverse_rotate_stack_end_to(biggest, 'a', stacks);
	else
		ft_rotate_stack_end_to(biggest, 'a', stacks);
	ft_pspush(stacks, 'a');
}

int		ft_smallest_since_to_beginning_a(t_stacks *stacks, int since,
											int a_amount)
{
	int		smallest;

	smallest = ft_find_smallest_since(stacks->a, a_amount, since);
	if (ft_distance(stacks->a, smallest) <= a_amount / 2)
	{
		ft_rotate_stack_to(smallest, 'a', stacks);
		ft_pspush(stacks, 'b');
		ft_reverse_rotate_stack_end_to(since, 'a', stacks);
		ft_pspush(stacks, 'a');
	}
	else
	{
		ft_reverse_rotate_stack_to(smallest, 'a', stacks);
		ft_pspush(stacks, 'b');
		ft_rotate_stack_end_to(since, 'a', stacks);
		ft_pspush(stacks, 'a');
	}
	return (smallest);
}

int		ft_is_basically_sorted(t_stacks *stacks, t_lst *stack, int smallest,
								int biggest)
{
	t_lst	*temp;

	if (stacks->a->nb == smallest)
		return (ft_list_is_sorted(stack));
	temp = stacks->a;
	while (temp->next)
	{
		if ((temp->nb == biggest && temp->next->nb == smallest) ||
			(temp->nb < temp->next->nb))
			temp = temp->next;
		else
			return (0);
	}
	while (stacks->a->nb != smallest)
		ft_psrotate(stacks, 'a');
	return (1);
}

int		ft_sort_stack_a(t_stacks *stacks, int a_amount)
{
	int		smallest;
	int		biggest;
	int		smallest_since;
	
	smallest = ft_find_smallest(stacks->a, a_amount);
	biggest = ft_find_biggest(stacks->a, a_amount);
	ft_smallest_to_the_biggest(stacks, smallest, biggest, a_amount);
	smallest_since = smallest;
	while (!(ft_is_basically_sorted(stacks, stacks->a, smallest, biggest)))
		smallest_since =
			ft_smallest_since_to_beginning_a(stacks, smallest_since, a_amount);
	return (smallest);
}