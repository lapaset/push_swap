/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:30:08 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 17:51:53 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_three_is_sorted(t_lst *stack, char c)
{
	if (c == 'a')
		return (stack->nb < stack->next->nb &&
		stack->next->nb < stack->next->next->nb);
	else if (c == 'b')
		return (stack->nb > stack->next->nb &&
		stack->next->nb > stack->next->next->nb);
	else
		ft_error();
	return (0);
}

void	ft_sort_a_of_three(t_stacks *stacks)
{
	if (ft_three_is_sorted(stacks->a, 'a'))
		return ;
	else if (stacks->a->nb > stacks->a->next->nb &&
		stacks->a->nb > stacks->a->next->next->nb)
	{
		ft_psrotate(stacks, 'a');
		ft_swap_a_if_first_is_bigger(stacks);
	}
	else if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, 'a');
	else if (stacks->a->nb < stacks->a->next->next->nb)  
	{
		ft_psrotate(stacks, 'a');
		ft_psswap(stacks, 'a');
		ft_psreverse_rotate(stacks, 'a');
	}
	else
		ft_psreverse_rotate(stacks, 'a');
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
		ft_pspush(stacks, 'a');
		ft_push_to_a_and_swap_if_needed(stacks);		
	}
	else if (stacks->b->next->nb > stacks->b->nb &&
			stacks->b->next->nb > stacks->b->next->next->nb &&
			stacks->b->nb > stacks->b->next->next->nb)
	//231
	{
		ft_pspush(stacks, 'a');
		ft_push_to_a_and_swap_if_needed(stacks);
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
				//here you can optimize one swap?
				ft_psreverse_rotate(stacks, 'b');
			}
		}
		if (amount > 1)
			ft_pspush(stacks, 'a');
		ft_push_to_a_and_swap_if_needed(stacks);
}

void	ft_sort_three_at_a(t_stacks *stacks)
{
	if (ft_three_is_sorted(stacks->a, 'a'))//123
		return ;
	if (stacks->a_len == 3)
		ft_sort_a_of_three(stacks);
	//remaining 132 213 231 321 312
	ft_swap_a_if_first_is_bigger(stacks);
	//remaining 132 123 231
	if (ft_three_is_sorted(stacks->a, 'a'))
		return ;
	//remaining 132 231
	ft_psrotate(stacks, 'a');
	ft_swap_a_if_first_is_bigger(stacks);
	ft_psreverse_rotate(stacks, 'a');
	ft_swap_a_if_first_is_bigger(stacks);
}

/*void	ft_sort_list_of_three(t_stacks *stacks)
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
}*/
