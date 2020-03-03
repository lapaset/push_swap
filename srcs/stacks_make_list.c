/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_make_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:14:40 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 10:58:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst			*ft_new_elem(int nb)
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
	nb = ft_atoi_push_swap(str);
	while (stack)
	{
		if (nb == stack->nb)
			ft_error();
		stack = stack->next;
	}
	return (nb);
}

int			ft_len(char *str)
{
	int		len;

	len = 0;
	while (*str != '\0' && *str != ' ')
	{
		str++;
		len++;
	}
	if (*str == ' ')
		len++;
	return (len);
}

void		ft_params_to_list(int arg, char **argv, t_stacks *stacks)
{
	int		i;
	int		j;

	stacks->b_len = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->b_end = NULL;
	i = 1;
	stacks->a = ft_new_elem(ft_check_data(argv[i], stacks->a));
	stacks->a_end = stacks->a;
	stacks->a_len = 1;
	j = ft_len(&argv[i][0]);
	while (i < arg)
	{
		while (argv[i][j] != '\0')
		{
			stacks->a_end = ft_add_elem_to_end(stacks->a_end,
									ft_new_elem(ft_check_data(&argv[i][j], stacks->a)));
			stacks->a_len++;
			j += ft_len(&argv[i][j]);
		}
		i++;
		j = 0;
	}
}