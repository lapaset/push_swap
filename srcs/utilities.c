/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:15:59 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:58:06 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_lst(t_lst *lst)
{
	while (lst)
	{
		ft_printf("%d ", lst->nb);
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

void	ft_print_result(t_stacks *stacks)
{
	if (ft_list_is_sorted(stacks->a) && stacks->b == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

void	ft_error(void)
{
	ft_putendl("Error");
	exit(1);
}

int			ft_atoi_checker(const char *str)
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
