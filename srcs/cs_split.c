/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:03:50 by llahti            #+#    #+#             */
/*   Updated: 2020/02/20 12:00:47 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_rest_is_bigger(int pivot, t_lst *lst, int i, int len)
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

void     ft_a_split(t_stacks *stacks, int a_pivot)
{
	int     i;
	int		len;
	int     pushed;
	
	len = stacks->a_len;
	i = 0;
	pushed = 0;
	while (i < len)
	{
		if (ft_rest_is_bigger(a_pivot, stacks->a, i, len))
			break ;
		if (stacks->a->nb > a_pivot)
			ft_psrotate(stacks, 'a');
		else
		{
			ft_pspush(stacks, 'b');
			pushed++;
		}
		i++;
	}
}

void    ft_initial_split(t_stacks *stacks, int pivot, int b_pivot)
{
	int     i;
	int		len;
	int		pushed;

	len = stacks->a_len;
	i = 0;
	pushed = 0;
	while (i < len)
	{
		if (ft_rest_is_bigger(pivot, stacks->a, i, len))
			break ;
		if (stacks->a->nb > pivot)
			ft_psrotate(stacks, 'a');
		else
		{
			ft_pspush(stacks, 'b');
			pushed++;
			if (stacks->b->nb <= b_pivot)
				ft_psrotate(stacks, 'b');
		}
		i++;
	}
}

int		ft_cs_split(int pivot, int b_pivot, t_stacks *stacks)
{
	int		a_pivot;

	ft_initial_split(stacks, pivot, b_pivot);
	a_pivot = ft_pivot(stacks->a, ft_average(stacks->a, stacks->a_len), stacks->a_len);
	ft_a_split(stacks, a_pivot);
	return (a_pivot);
}