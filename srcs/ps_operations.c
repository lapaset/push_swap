/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:35:13 by llahti            #+#    #+#             */
/*   Updated: 2020/02/17 14:19:51 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_psswap(t_stacks *stacks, char c)
{
	if (c == 'c')
		ft_swap(stacks, 's');
	else
		ft_swap(stacks, c);
	ft_printf("s%c\n", c);
}

void		ft_pspush(t_stacks *stacks, char c)
{
	ft_push(stacks, c);
	ft_printf("p%c\n", c);
}

void		ft_psrotate(t_stacks *stacks, char c)
{
	if (c == 'c')
	{
		ft_rotate(stacks, 'r');
		ft_printf("rr\n");
		return ;
	}
	ft_rotate(stacks, c);
	ft_printf("r%c\n", c);
}

void		ft_psreverse_rotate(t_stacks *stacks, char c)
{
	if (c == 'c')
	{
		ft_reverse_rotate(stacks, 'r');
		ft_printf("rrr\n");
		return ;
	}
	ft_reverse_rotate(stacks, c);
	ft_printf("rr%c\n", c);
}
