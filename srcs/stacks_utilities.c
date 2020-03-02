/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:15:59 by llahti            #+#    #+#             */
/*   Updated: 2020/03/02 12:52:37 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_print_lst_with_pivots(t_lst *lst, int a_pivot, int pivot, int b_pivot)
{
	while (lst)
	{
		if (lst->nb >= a_pivot)
			ft_printf("{blue}");
		else if (lst->nb >= pivot)
			ft_printf("{red}");
		else if (lst->nb >= b_pivot)
			ft_printf("{yellow}");
		else
			ft_printf("{green}");
		ft_printf("%d{eoc} ", lst->nb);
		lst = lst->next;
	}
	ft_printf("\n");
}

void		ft_print_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->nb >= 50)
			ft_printf("{blue}");
		else if (lst->nb >= 0)
			ft_printf("{red}");
		else if (lst->nb >= -50)
			ft_printf("{yellow}");
		else
			ft_printf("{green}");
		ft_printf("%d{eoc} ", lst->nb);
		lst = lst->next;
	}
	ft_printf("\n");
}

int		ft_list_is_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void		ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int			ft_atoi_push_swap(const char *str)
{
	long	a;
	int 	sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' | *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	a = 0;
	while (ft_isdigit(*str))
	{
		a = a * 10 + (*str - 48);
		str++;
	}
	if (a * sign < -2147483648 || a * sign > 2147483647)
		ft_error();
	return ((int)a * sign);
}

