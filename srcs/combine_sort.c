/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:08:43 by llahti            #+#    #+#             */
/*   Updated: 2020/02/19 11:05:38 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_check_if_rest_is_bigger(int pivot, t_lst *lst, int i, int amount)
{
	while (i < amount && lst->next)
	{
		if (lst->nb <= pivot)
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

static int 	ft_pivot_under(t_lst *lst, int average)
{
	int		pivot;

	pivot = lst->nb;
	while (lst)
	{
		if (lst->nb == average)
			return (average);
		if (ft_abs(lst->nb - average) < ft_abs(pivot - average))
			pivot = lst->nb;
		lst = lst->next;
	}
	return (pivot);
}

static int		ft_average_under(int pivot, t_lst *lst)
{
	int		sum;
	int		amount;

	sum = 0;
	amount = 0;
	while (lst)
	{
		if (lst->nb < pivot)
		{
			sum += lst->nb;
			amount++;
		}
		lst = lst->next;
	}
	return (sum / amount);
}

int    ft_initial_split(t_stacks *stacks, int amount, int pivot, int b_pivot)
{
	int     i;
	int     a_amount;

	i = 0;
	a_amount = 0;
	while (i < amount)
	{
		if (ft_check_if_rest_is_bigger(pivot, stacks->a, i, amount))
			break ;
		if (stacks->a->nb > pivot)
		{
			ft_psrotate(stacks, 'a');
			a_amount++;
		}
		else if (stacks->a->nb > b_pivot)
			ft_pspush(stacks, 'b');
		else
		{
			ft_pspush(stacks, 'b');
			ft_psrotate(stacks, 'b');
		}
		i++;
	}
	a_amount += amount - i;
	return (a_amount);
}

int     ft_split_a(t_stacks *stacks, int amount, int a_pivot)
{
	int     i;
	int     a_amount;
	
	i = 0;
	a_amount = 0;
	while (i < amount)
	{
		if (ft_check_if_rest_is_bigger(a_pivot, stacks->a, i, amount))
			break ;
		if (stacks->a->nb > a_pivot)
		{
			ft_psrotate(stacks, 'a');
			a_amount++;
		}
		else
			ft_pspush(stacks, 'b');
		i++;
	}
	a_amount += amount - i;
	return (a_amount);
}

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
int		ft_part_to_a(t_stacks *stacks, int pivot, int biggest, int b_amount)
{
	int		rotated;

	rotated = 0;
	while (!(rotated == 0 && stacks->b->nb <= pivot))
	{
		if (!ft_is_rotated(biggest, stacks->b, pivot))
			rotated += ft_rotate_stack_to(biggest, 'b', stacks);
		else
			rotated -= ft_reverse_rotate_stack_to(biggest, 'b', stacks);
		ft_pspush(stacks, 'a');
		b_amount--;
		biggest = ft_find_biggest_since(stacks->b, b_amount, biggest);
	}
	return (b_amount);
}

void	ft_rest_to_a(t_stacks *stacks, int biggest, int b_amount)
{
	while (b_amount > 2)
	{
		if (ft_distance(stacks->b, biggest) <= b_amount / 2)
			ft_rotate_stack_to(biggest, 'b', stacks);
		else
			ft_reverse_rotate_stack_to(biggest, 'b', stacks);
		ft_pspush(stacks, 'a');
		b_amount--;
		biggest = ft_find_biggest_since(stacks->b, b_amount, biggest);
	}
	if (stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
	ft_pspush(stacks, 'a');
	ft_pspush(stacks, 'a');
}

void    ft_sort(t_stacks *stacks, int amount)
{
	int     pivot;
	int		a_pivot;
	int     b_pivot;
	int     a_amount;
	int     b_amount;

	pivot = ft_pivot(stacks->a, ft_average(stacks->a, amount), amount);
	b_pivot = ft_pivot_under(stacks->a, ft_average_under(pivot, stacks->a));
	a_amount = ft_initial_split(stacks, amount, pivot, b_pivot);
	a_pivot = ft_pivot(stacks->a, ft_average(stacks->a, a_amount), a_amount);
	a_amount = ft_split_a(stacks, a_amount, a_pivot);
	b_amount = amount - a_amount;
	ft_sort_stack_a(stacks, a_amount);
	b_amount = ft_part_to_a(stacks, pivot, a_pivot, b_amount);
	b_amount = ft_part_to_a(stacks, b_pivot, pivot, b_amount);
	ft_rest_to_a(stacks, b_pivot, b_amount);
}

//1210
//844
//620