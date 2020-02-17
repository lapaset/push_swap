/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/02/17 17:03:32 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_if_needed(t_stacks *stacks, char c)
{
	if ((c == 'a' && stacks->a && stacks->a->next &&
			stacks->a->nb > stacks->a->next->nb) ||
		(c == 'b' && stacks->b && stacks->b->next &&
		stacks->b->nb < stacks->b->next->nb) ||
		(c == 'c' && stacks->a && stacks->a->next &&
		stacks->b && stacks->b->next &&
		stacks->a->nb > stacks->a->next->nb &&
		stacks->b->nb < stacks->b->next->nb))
		ft_psswap(stacks, c);
	else if (c == 'c' && stacks->a && stacks->a->next &&
			stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (c == 'c' && stacks->b && stacks->b->next &&
			stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
}

void	ft_sort_three(t_stacks *stacks, char c)
{
	ft_swap_if_needed(stacks, c);
	ft_psrotate(stacks, c);
	ft_swap_if_needed(stacks, c);
	ft_psreverse_rotate(stacks, c);
	ft_swap_if_needed(stacks, c);
}

int 	ft_move_to_b(t_stacks *stacks, int pivot, int amount)
{
	int		ret;
	
	ret = 0;
	while (amount)
	{
		//ft_printf("amount: %d, a->nb: %d\n", amount, stacks->a->nb);
		if (stacks->a->nb <= pivot)
		{
			ft_pspush(stacks, 'b');
			//if (stacks->b > stacks->b->next)
			//	ft_psswap(stacks, 'b');
		}
		else
		{
			ft_psrotate(stacks, 'a');
			ret++;
		}
		amount--;
	}
	return (ret);
}

/*int 	ft_move_to_a(t_stacks *stacks, int pivot, int amount)
{
	int		ret;
	
	ret = 0;
	while (amount)
	{
		if (stacks->a->nb >= pivot)
			ft_pspush(stacks, 'a');
		else
		{
			ft_psrotate(stacks, 'b');
			ret++;
		}
		amount--;
	}
	return (ret);
}*/

int 	ft_pivot(t_lst *lst, int average, int amount)
{
	int		pivot;
	int		i;

	pivot = lst->nb;
	i = 0;
	while (i < amount)
	{
		if (ft_abs(lst->nb - average) < ft_abs(pivot - average))
			pivot = lst->nb;
		lst = lst->next;
		i++;
	}
	return (pivot);
}

int		ft_average(t_lst *lst, int amount)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (i < amount)
	{
		sum += lst->nb;
		lst = lst->next;
		i++;
	}
	return (sum / amount);
}

/*void	ft_quicksort_b(t_stacks *stacks, int amount)
{
	int		average;
	int		pivot;
	int		rotated;
	int 	i;

	if (amount > 3)
	{
		average = ft_average(stacks->b, amount);
		pivot = ft_pivot(stacks->b, average, amount);

		rotated = ft_move_to_a(stacks, pivot, amount);
		i = 0;
		while (i < rotated)
		{
			ft_psreverse_rotate(stacks, 'b');
			i++;
		}
		ft_quicksort_b(stacks, rotated);
	}
	else if (amount == 3)
	{
		ft_sort_three(stacks, 'b');
		i = 0;
		while (i < 3)
		{
			ft_pspush(stacks, 'a');
			i++;
		}
	}
	else if (amount == 2)
	{
		ft_swap_if_needed(stacks, 'b');
		i = 0;
		while (i < 3)
		{
			ft_pspush(stacks, 'a');
			i++;
		}
	}
	else
		ft_pspush(stacks, 'a');
}*/

void	ft_quicksort(t_stacks *stacks, int amount)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_pivot(stacks->a, average, amount);

		amount_next = ft_move_to_b(stacks, pivot, amount);
		ft_quicksort(stacks, amount_next);

		ft_print_lst(stacks->a);
		ft_print_lst(stacks->b);


		//try pushing values one by one and for the amount moved to a swap if needed
		rest = amount - amount_next;
		if (rest == 3)
		{
			while (rest)
			{
				ft_pspush(stacks, 'a');
				rest--;		
			}
			ft_sort_three(stacks, 'a');
		}
	}
	else if (amount == 3)
		ft_sort_three(stacks, 'c');
	else if (amount == 2)
		ft_swap_if_needed(stacks, 'c');
}
