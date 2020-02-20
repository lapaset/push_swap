/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:15:59 by llahti            #+#    #+#             */
/*   Updated: 2020/02/19 15:28:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->nb < 6 && lst->nb > -48)
			ft_printf("{red}");
		else if (lst->nb > 4)
			ft_printf("{yellow}");
		ft_printf("%d{eoc} ", lst->nb);
		lst = lst->next;
	}
	ft_printf("\n");
}

int		ft_list_is_sorted(t_lst *stack)
{
	//remove print
	//ft_print_lst(stack);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}


//maybe this to another c file
void	ft_print_result(t_stacks *stacks)
{
	if (ft_list_is_sorted(stacks->a) && stacks->b == NULL)
		ft_putendl("OK");
	else
		ft_putendl("KO");
}

void	ft_error(void)
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

