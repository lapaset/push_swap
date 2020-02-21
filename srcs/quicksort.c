/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/02/21 10:19:07 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_if_needed(t_stacks *stacks, char c)
{
	if (c == 'a' && stacks->a && stacks->a->next &&
			stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (c == 'b' && stacks->b && stacks->b->next &&
		stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
}

void	ft_swap_if_first_is_bigger(t_stacks *stacks, char c)
{
	if (stacks->b->nb > stacks->b->next->nb)
		ft_psswap(stacks, c);
}

void	ft_sort_list_of_three(t_stacks *stacks)
{
	if (stacks->a->nb > stacks->a->next->nb &&
		stacks->a->nb > stacks->a->next->next->nb)
	{
		ft_psrotate(stacks, 'a');
		ft_swap_if_first_is_bigger(stacks, 'a');
	}
	else if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (stacks->a->next->nb > stacks->a->next->next->nb)
	{
		ft_psswap(stacks, 'a');
		ft_psrotate(stacks, 'a');
	}
	else
		ft_psreverse_rotate(stacks, 'a');
}

void	ft_sort_three(t_stacks *stacks)
{
	if (ft_list_is_sorted(stacks->a))
		return ;
	if (stacks->a_len == 3)
		ft_sort_list_of_three(stacks);
	ft_swap_if_needed(stacks, 'a');
	if (ft_list_is_sorted(stacks->a))
		return ;
	ft_psrotate(stacks, 'a');
	ft_swap_if_needed(stacks, 'a');
	ft_psreverse_rotate(stacks, 'a');
	ft_swap_if_needed(stacks, 'a');
}

int 	ft_move_from(char from, t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (amount)
	{
		//ft_printf("amount: %d, a->nb: %d\n", amount, stacks->a->nb);
		if (from == 'a' && stacks->a->nb <= pivot)
			ft_pspush(stacks, 'b');
		else if (from == 'a')
		{
			ft_psrotate(stacks, 'a');
			rotated++;
		}
		else if (from == 'b' && stacks->b->nb >= pivot)
			ft_pspush(stacks, 'a');
		else if (from == 'b')
		{
			ft_psrotate(stacks, 'b');
			rotated++;
		}
		amount--;
	}
	if (!first)
	{
		i = rotated;
		while (i)
		{
			ft_psreverse_rotate(stacks, from);
			i--;
		}
	}
	return (rotated);
}

void	ft_quicksort_b(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	//int		amount_next;
	int 	i;
	int		rotated;

	if (amount <= 3)
	{
		i = amount;
		while (i)
		{
			ft_pspush(stacks, 'a');
			i--;		
		}
		if (amount == 3)
			ft_sort_three(stacks);
		if (amount == 2)
			ft_swap_if_needed(stacks, 'a');
		return ;
	}
	average = ft_average(stacks->b, amount);
	pivot = ft_pivot(stacks->b, average, amount);
	//ft_printf("amount: %d average: %d pivot: %d\n", amount, average, pivot);
	ft_printf("at b before move stack a: ");
	ft_print_lst(stacks->a);
	ft_printf("at b before move stack b: ");
	ft_print_lst(stacks->b);
	rotated = ft_move_from('b', stacks, pivot, amount, first);
	ft_printf("at b after move stack a: ");
	ft_print_lst(stacks->a);
	ft_printf("at b after move stack b: ");
	ft_print_lst(stacks->b);
	ft_quicksort(stacks, amount - rotated, first);
	ft_quicksort_b(stacks, rotated, first);
}

void	ft_quicksort(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_pivot(stacks->a, average, amount);
		ft_printf("at a before move stack a: ");
		ft_print_lst(stacks->a);
		ft_printf("at a before move stack b: ");
		ft_print_lst(stacks->b);
		amount_next = ft_move_from('a', stacks, pivot, amount, first);
		ft_printf("at a after move stack a: ");
		ft_print_lst(stacks->a);
		ft_printf("at a after move stack b: ");
		ft_print_lst(stacks->b);
		ft_quicksort(stacks, amount_next, first);

		//ft_print_lst(stacks->a);
		//ft_print_lst(stacks->b);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, first);
	}
	else if (amount == 3)
		ft_sort_three(stacks);
	else if (amount == 2)
		ft_swap_if_needed(stacks, 'a');
}
/*void	ft_swap_if_needed(t_stacks *stacks, char c)
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

void	ft_swap_if_first_is_bigger(t_stacks *stacks, char c)
{
	if (stacks->b->nb > stacks->b->next->nb)
		ft_psswap(stacks, c);
}

void	ft_sort_three_at_a(t_stacks *stacks)
{
	if (ft_list_is_sorted(stacks->a))
		return ;
	if (stacks->a_len == 3)
	{
		if (stacks->a->nb > stacks->a->next->nb &&
			stacks->a->nb > stacks->a->next->next->nb)
		{
			ft_psrotate(stacks, 'a');
			ft_swap_if_first_is_bigger(stacks, 'a');
		}
		else if (stacks->a->nb > stacks->a->next->nb)
			ft_psswap(stacks, 'a');
		else if (stacks->a->next->nb > stacks->a->next->next->nb)
		{
			ft_psswap(stacks, 'a');
			ft_psrotate(stacks, 'a');
		}
		else
			ft_psreverse_rotate(stacks, 'a');
	}
	else
	{
		if (stacks->a->nb > stacks->a->next->nb &&
			stacks->a->nb > stacks->a->next->next->nb)
		{
			ft_psswap(stacks, 'a');
			ft_psrotate(stacks, 'a');
			ft_psswap(stacks, 'a');
			ft_psreverse_rotate(stacks, 'a');
			ft_swap_if_first_is_bigger(stacks, 'a');
		}
		else if (stacks->a->nb > stacks->a->next->nb)
			ft_psswap(stacks, 'a');
		else if (stacks->a->next->nb > stacks->a->next->next->nb)
		{
			ft_psrotate(stacks, 'a');
			ft_psswap(stacks, 'a');
			ft_psreverse_rotate(stacks, 'a');
		}
		else
		{
			ft_psrotate(stacks, 'a');
			ft_psswap(stacks, 'a');
			ft_psreverse_rotate(stacks, 'a');
			ft_psswap(stacks, 'a');
		}
	}
}

int 	ft_move_from(char from, t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (amount)
	{
		//ft_printf("amount: %d, a->nb: %d\n", amount, stacks->a->nb);
		if (from == 'a' && stacks->a->nb <= pivot)
			ft_pspush(stacks, 'b');
		else if (from == 'a')
		{
			ft_psrotate(stacks, 'a');
			rotated++;
		}
		else if (from == 'b' && stacks->b->nb >= pivot)
			ft_pspush(stacks, 'a');
		else if (from == 'b')
		{
			ft_psrotate(stacks, 'b');
			rotated++;
		}
		amount--;
	}
	if (!first)
	{
		ft_printf("before reverse rotate stack a: ");
		ft_print_lst(stacks->a);
		ft_printf("before reverse rotate stack b: ");
		ft_print_lst(stacks->b);
		i = rotated;
		while (i)
		{
			ft_psreverse_rotate(stacks, from);
			i--;
		}
	}
	return (rotated);
}

void	ft_push_bigger_of_two_to_a(t_stacks *stacks)
{
	if (stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
	ft_pspush(stacks, 'a');
}

void	ft_push_three_or_less_to_a(t_stacks *stacks, int amount)
{
		if (amount == 3)
		{
			if (stacks->b->nb < stacks->b->next->nb &&
				stacks->b->nb < stacks->b->next->next->nb)
			{
				ft_psrotate(stacks, 'b');
				ft_psswap(stacks, 'b');
				ft_pspush(stacks, 'a');
				if (stacks->b->nb > stacks->b_end->nb)
				{
					ft_pspush(stacks, 'a');
					ft_psreverse_rotate(stacks, 'b');
				}
				else
				{
					ft_psreverse_rotate(stacks, 'b');
					ft_push(stacks, 'a');
				}
				ft_pspush(stacks, 'a');
				return ;
			}
			ft_push_bigger_of_two_to_a(stacks);
		}
		if (amount > 1)
			ft_push_bigger_of_two_to_a(stacks);
		ft_pspush(stacks, 'a');
}

void	ft_quicksort_b(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	//int		amount_next;
	//int 	i;
	int		rotated;

	if (amount <= 3)
	{
		ft_push_three_or_less_to_a(stacks, amount);
		return ;
	}
	average = ft_average(stacks->b, amount);
	pivot = ft_pivot(stacks->b, average, amount);
	//ft_printf("amount: %d average: %d pivot: %d\n", amount, average, pivot);
	rotated = ft_move_from('b', stacks, pivot, amount, first);
	ft_printf("at b stack a: ");
	ft_print_lst(stacks->a);
	ft_printf("at b stack b: ");
	ft_print_lst(stacks->b);
	ft_quicksort(stacks, amount - rotated, first);
	ft_quicksort_b(stacks, rotated, first);
}

void	ft_quicksort(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_pivot(stacks->a, average, amount);

		amount_next = ft_move_from('a', stacks, pivot, amount, first);
		ft_printf("at a stack a: ");
		ft_print_lst(stacks->a);
		ft_printf("at a stack b: ");
		ft_print_lst(stacks->b);
		ft_quicksort(stacks, amount_next, first);

		//ft_print_lst(stacks->a);
		//ft_print_lst(stacks->b);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, first);
	}
	else if (amount == 3)
		ft_sort_three_at_a(stacks);
	else if (amount == 2)
		ft_swap_if_first_is_bigger(stacks, 'a');
}
*/
//find out where the numbers to be moved are and if there are some left
//maybe handle the cases when there are less than six numbers separately?
//sort numbers before sending them back to a??

//852
//831
//813
//915
//852
//842
//832