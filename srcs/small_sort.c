/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 10:16:15 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 17:08:29 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_small_rest_is_bigger(int pivot, t_lst *lst, int i, int len)
{
	while (i < len && lst)
	{
		if (lst->nb < pivot)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

void	ft_small_a_split(t_stacks *stacks, int a_pivot)
{
	int		i;
	int		len;
	int		pushed;

	len = stacks->a_len;
	i = 0;
	pushed = 0;
	while (i < len && !ft_small_rest_is_bigger(a_pivot, stacks->a, i, len))
	{
		while (stacks->a->nb >= a_pivot && i < len)
		{
			ft_psrotate(stacks, 'a');
			i++;
		}
		ft_pspush(stacks, 'b');
		pushed++;
		i++;
	}
}

void	ft_small_sort(t_stacks *stacks)
{
	int		pivot;

	pivot = ft_cs_pivot(stacks);
	ft_small_a_split(stacks, pivot);
	ft_sort_a(stacks);
	ft_rest_to_a(stacks);
}
