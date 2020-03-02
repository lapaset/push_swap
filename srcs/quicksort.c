/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:27:23 by llahti            #+#    #+#             */
/*   Updated: 2020/03/02 14:50:18 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_qs_pivot(t_lst *stack, int average, int amount)
{
	int		pivot;
	int		i;

	pivot = stack->nb;
	i = 0;
	while (i < amount && stack)
	{
		if (stack->nb == average)
			return (average);
		if (ft_abs(stack->nb - average) < ft_abs(pivot - average))
			pivot = stack->nb;
		stack = stack->next;
		i++;
	}
	return (pivot);
}

void	ft_swap_if_first_is_bigger(t_stacks *stacks, char c)
{
	if (stacks->a->nb > stacks->a->next->nb)
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

int		ft_three_is_sorted(t_lst *stack)
{
	return (stack->nb < stack->next->nb &&
		stack->next->nb < stack->next->next->nb);
}

void	ft_qs_sort_three(t_stacks *stacks)
{
	if (ft_three_is_sorted(stacks->a))//123
		return ;
	if (stacks->a_len == 3)
		ft_sort_list_of_three(stacks);
	//remaining 132 213 231 321 312
	ft_swap_if_first_is_bigger(stacks, 'a');
	//remaining 132 123 231
	if (ft_three_is_sorted(stacks->a))
		return ;
	//remaining 132 231
	ft_psrotate(stacks, 'a');
	ft_swap_if_first_is_bigger(stacks, 'a');
	ft_psreverse_rotate(stacks, 'a');
	ft_swap_if_first_is_bigger(stacks, 'a');
}

int		ft_rest_are_bigger(t_lst *stack, int amount, int pivot)
{
	while (amount)
	{
		if (stack->nb <= pivot)
			return (0);
		stack = stack->next;
		amount--;
	}
	return (1);
}

int 	ft_move_from_a(t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (!ft_rest_are_bigger(stacks->a, amount, pivot) && amount)
	{
		if (stacks->a->nb <= pivot)
			ft_pspush(stacks, 'b');
		else
		{
			ft_psrotate(stacks, 'a');
			rotated++;
		}
		amount--;
	}
	if (!first)
	{
		i = rotated;
		while (i)
		{
			ft_psreverse_rotate(stacks, 'a');
			i--;
		}
	}
	return (rotated + amount);
}

int		ft_rest_are_smaller(t_lst *stack, int amount, int pivot)
{
	while (amount)
	{
		if (stack->nb >= pivot)
			return (0);
		stack = stack->next;
		amount--;
	}
	return (1);
}

int 	ft_move_from_b(t_stacks *stacks, int pivot, int amount, int first)
{
	int		rotated;
	int		i;
	
	rotated = 0;
	while (!ft_rest_are_smaller(stacks->b, amount, pivot) && amount)
	{
		if (stacks->b->nb >= pivot)
			ft_pspush(stacks, 'a');
		else
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
			ft_psreverse_rotate(stacks, 'b');
			i--;
		}
	}
	return (rotated + amount);
}

void	ft_push_bigger_of_two_to_a(t_stacks *stacks)
{
	if (stacks->b->nb < stacks->b->next->nb)
		ft_psswap(stacks, 'b');
	ft_pspush(stacks, 'a');
}

void	ft_push_list_of_three_to_a(t_stacks *stacks)
{
	if (stacks->b->nb < stacks->b->next->nb &&
		stacks->b->next->nb < stacks->b->next->next->nb)
	//123
	{
		ft_psrotate(stacks, 'b');
		ft_psswap(stacks, 'b');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
		return ;
	}
	if (stacks->b->nb > stacks->b->next->nb &&
		stacks->b->nb > stacks->b->next->next->nb)
	//321 312
	{
		ft_pspush(stacks, 'a');
		ft_push_bigger_of_two_to_a(stacks);
		ft_pspush(stacks, 'a');
	}
	else if (stacks->b->next->nb > stacks->b->nb &&
			stacks->b->next->nb > stacks->b->next->next->nb &&
			stacks->b->nb > stacks->b->next->next->nb)
	//231
	{
		ft_push_bigger_of_two_to_a(stacks);
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
	}
	else if(stacks->b->next->nb > stacks->b->nb &&
			stacks->b->next->nb > stacks->b->next->next->nb)
	//132
	{
		ft_psrotate(stacks, 'b');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
	}
	else
	//213
	{
		ft_psreverse_rotate(stacks, 'b');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
		ft_pspush(stacks, 'a');
	}
}

void	ft_push_three_or_less_to_a(t_stacks *stacks, int amount)
{	
		if (stacks->b_len == 3 && amount == 3)
		{
			ft_push_list_of_three_to_a(stacks);
			return;
		}
		if (amount == 3)
		{
			if (stacks->b->nb < stacks->b->next->nb &&
				stacks->b->next->nb < stacks->b->next->next->nb)
			//123
			{
				ft_psrotate(stacks, 'b');
				ft_psswap(stacks, 'b');
				ft_pspush(stacks, 'a');
				ft_pspush(stacks, 'a');
				ft_psreverse_rotate(stacks, 'b');
				ft_pspush(stacks, 'a');
				return ;
			}
			if (stacks->b->nb > stacks->b->next->nb &&
				stacks->b->nb > stacks->b->next->next->nb)
			//321 312
				ft_pspush(stacks, 'a');
			else if (stacks->b->next->nb > stacks->b->nb &&
					(stacks->b->next->nb > stacks->b->next->next->nb))
			//231 132
			{
				ft_psswap(stacks, 'b');
				ft_pspush(stacks, 'a');
			}
			else
			//213
			{
				ft_psrotate(stacks, 'b');
				ft_psswap(stacks, 'b');
				ft_pspush(stacks, 'a');
				//here you can optimize one swap
				ft_psreverse_rotate(stacks, 'b');
			}
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
		//ft_printf("at b amount is less than 3: %d\n", amount);
		ft_push_three_or_less_to_a(stacks, amount);
		/*ft_printf("at b after push three or less a: ");
		ft_print_lst(stacks->a);
		ft_printf("at b after push three or less b: ");
		ft_print_lst(stacks->b);*/
		return ;
	}
	average = ft_average(stacks->b, amount);
	pivot = ft_qs_pivot(stacks->b, average, amount);
	//ft_printf("pivot at b: %d\n", pivot);
	//ft_printf("amount: %d average: %d pivot: %d\n", amount, average, pivot);
	/*ft_printf("amount: %d at b before move stack a: ", amount);
	ft_print_lst(stacks->a);
	ft_printf("amount: %d at b before move stack b: ", amount);
	ft_print_lst(stacks->b);*/
	rotated = ft_move_from_b(stacks, pivot, amount, first);
	/*ft_printf("at b after move stack a: ");
	ft_print_lst(stacks->a);
	ft_printf("at b after move stack b: ");
	ft_print_lst(stacks->b);*/
	ft_quicksort(stacks, amount - rotated, first);
	ft_quicksort_b(stacks, rotated, first);
}

void	ft_quicksort(t_stacks *stacks, int amount, int first)
{
	int		pivot;
	int		average;
	int		amount_next;
	int		rest;

	if (ft_list_is_sorted(stacks->a) && stacks->b_len == 0)
		return ;
	if (amount > 3)
	{
		average = ft_average(stacks->a, amount);
		pivot = ft_qs_pivot(stacks->a, average, amount);
		//ft_printf("pivot at a: %d\n", pivot);
		/*ft_printf("amount: %d at a before move stack a: ", amount);
		ft_print_lst(stacks->a);
		ft_printf("amount: %d at a before move stack b: ", amount);
		ft_print_lst(stacks->b);*/
		amount_next = ft_move_from_a(stacks, pivot, amount, first);
		/*ft_printf("at a after move stack a: ");
		ft_print_lst(stacks->a);
		ft_printf("at a after move stack b: ");
		ft_print_lst(stacks->b);*/
		ft_quicksort(stacks, amount_next, first);

		//ft_print_lst(stacks->a);
		//ft_print_lst(stacks->b);
		rest = amount - amount_next;
		first = 0;
		ft_quicksort_b(stacks, rest, first);
	}
	else if (amount == 3)
		ft_qs_sort_three(stacks);
	else if (amount == 2)
		ft_swap_if_first_is_bigger(stacks, 'a');
}


//todo: count real pivot