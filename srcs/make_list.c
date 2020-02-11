/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:14:40 by llahti            #+#    #+#             */
/*   Updated: 2020/02/11 11:33:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_lst	*ft_new_elem(int nb)
{
	t_lst 	*elem;

	if (!(elem = (t_lst*)malloc(sizeof(t_lst))))
		exit(1);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

t_lst			*ft_add_elem_to_start(t_lst *stack, t_lst *elem)
{
	elem->next = stack;
	return (elem);
}

t_lst			*ft_add_elem_to_end(t_lst *stack_last, t_lst *elem)
{
	stack_last->next = elem;
	return (elem);
}

static int		ft_check_data(char *str, t_lst *stack)
{
	int		nb;

	if (!ft_isdigit(*str) && *str != '-' && *str != '+')
		ft_error();
	nb = ft_atoi_checker(str);
	while (stack)
	{
		if (nb == stack->nb)
			ft_error();
		stack = stack->next;
	}
	return (nb);
}

void			ft_params_to_list(int arg, char **argv, t_stacks *stacks)
{
	int		i;

	stacks->size = arg - 1;
	stacks->a = NULL;
	stacks->a = ft_new_elem(ft_check_data(argv[1], stacks->a));
	stacks->a_end = stacks->a;
	stacks->b = NULL;
	stacks->b_end = NULL;
	i = 2;
	while (i < arg)
	{
		stacks->a_end = ft_add_elem_to_end(stacks->a_end,
								ft_new_elem(ft_check_data(argv[i], stacks->a)));
		i++;
	}
}