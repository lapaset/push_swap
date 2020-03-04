/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:15:59 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:28:34 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			ft_list_is_sorted(t_lst *stack)
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
	int		sign;

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

void		(**g_ft_operations(void))(t_stacks*, char)
{
	void	(**operations)(t_stacks*, char);

	operations = malloc(sizeof(void*) * 11);
	operations[0] = &ft_swap;
	operations[1] = &ft_swap;
	operations[2] = &ft_swap;
	operations[3] = &ft_push;
	operations[4] = &ft_push;
	operations[5] = &ft_rotate;
	operations[6] = &ft_rotate;
	operations[7] = &ft_rotate;
	operations[8] = &ft_reverse_rotate;
	operations[9] = &ft_reverse_rotate;
	operations[10] = &ft_reverse_rotate;
	return (operations);
}
