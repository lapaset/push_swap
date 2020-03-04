/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:03:50 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 11:34:38 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_rest_is_bigger(int pivot, t_lst *lst, int i, int len)
{
	while (i < len && lst->next)
	{
		if (lst->nb <= pivot)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

void		ft_a_split(t_stacks *stacks, int a_pivot)
{
	int		i;
	int		len;
	int		pushed;

	len = stacks->a_len;
	i = 0;
	pushed = 0;
	while (i < len && !ft_rest_is_bigger(a_pivot, stacks->a, i, len))
	{
		while (stacks->a->nb > a_pivot && i < len)
		{
			ft_psrotate(stacks, 'a');
			i++;
		}
		ft_pspush(stacks, 'b');
		pushed++;
		i++;
	}
}

static void	ft_initial_split(t_stacks *stacks, int pivot, int b_pivot)
{
	int		i;
	int		len;
	int		pushed;

	len = stacks->a_len;
	i = 0;
	pushed = 0;
	while (i < len && !ft_rest_is_bigger(pivot, stacks->a, i, len))
	{
		while (stacks->a->nb > pivot && i < len)
		{
			ft_psrotate(stacks, 'a');
			i++;
		}
		ft_pspush(stacks, 'b');
		pushed++;
		if (stacks->b->nb <= b_pivot && stacks->b_len > 1)
			ft_psrotate(stacks, 'b');
		i++;
	}
}

int			ft_cs_split(int pivot, int b_pivot, t_stacks *stacks, int *arr)
{
	int		a_pivot;

	ft_initial_split(stacks, pivot, b_pivot);
	a_pivot = ft_pivot_from_arr(arr, stacks->a, stacks->a_len);
	ft_a_split(stacks, a_pivot);
	return (a_pivot);
}
