/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:54:18 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 13:08:16 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_swap(t_stacks *stacks, char c)
{
	t_lst	*stack;
	int		temp;

	if (c == 'a' && stacks->a && stacks->a->next)
		stack = stacks->a;
	else if (c == 'b' && stacks->b && stacks->b->next)
		stack = stacks->b;
	else if (c == 's')
	{
		ft_swap(stacks, 'a');
		ft_swap(stacks, 'b');
		return ;
	}
	else
		return ;
	temp = stack->nb;
	stack->nb = stack->next->nb;
	stack->next->nb = temp;
}

void		ft_push(t_stacks *stacks, char c)
{
	t_lst	*temp;

	if (c == 'a' && stacks->b)
	{
		temp = stacks->b->next;
		stacks->a = ft_add_elem_to_start(stacks->a, stacks->b);
		stacks->b = temp;
		if (!stacks->a->next)
			stacks->a_end = stacks->a;
		stacks->a_len++;
		stacks->b_len--;
	}
	else if (c == 'b' && stacks->a)
	{
		temp = stacks->a->next;
		stacks->b = ft_add_elem_to_start(stacks->b, stacks->a);
		stacks->a = temp;
		if (!stacks->b->next)
			stacks->b_end = stacks->b;
		stacks->a_len--;
		stacks->b_len++;
	}
	else
		return ;
}

void		ft_rotate(t_stacks *stacks, char c)
{
	t_lst	*temp;

	if (c == 'a' && stacks->a != stacks->a_end)
	{
		temp = stacks->a->next;
		stacks->a->next = NULL;
		stacks->a_end = ft_add_elem_to_end(stacks->a_end, stacks->a);
		stacks->a = temp;
	}
	else if (c == 'b' && stacks->b != stacks->b_end)
	{
		temp = stacks->b->next;
		stacks->b->next = NULL;
		stacks->b_end = ft_add_elem_to_end(stacks->b_end, stacks->b);
		stacks->b = temp;
	}
	else if (c == 'r')
	{
		ft_rotate(stacks, 'a');
		ft_rotate(stacks, 'b');
	}
	else
		return ;
}

static void	ft_move_from_end_to_start(t_stacks *stacks, char stack)
{
	t_lst	*temp;

	if (stack == 'a' && stacks->a != stacks->a_end)
	{
		temp = stacks->a;
		while (temp->next != stacks->a_end)
			temp = temp->next;
		stacks->a = ft_add_elem_to_start(stacks->a, stacks->a_end);
		temp->next = NULL;
		stacks->a_end = temp;
	}
	else if (stack == 'b' && stacks->b != stacks->b_end)
	{
		temp = stacks->b;
		while (temp->next != stacks->b_end)
			temp = temp->next;
		stacks->b = ft_add_elem_to_start(stacks->b, stacks->b_end);
		temp->next = NULL;
		stacks->b_end = temp;
	}
}

void		ft_reverse_rotate(t_stacks *stacks, char c)
{
	if (c == 'a' || c == 'b')
		ft_move_from_end_to_start(stacks, c);
	else if (c == 'r')
	{
		ft_reverse_rotate(stacks, 'a');
		ft_reverse_rotate(stacks, 'b');
	}
	else
		return ;
}
