/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:14:40 by llahti            #+#    #+#             */
/*   Updated: 2020/02/06 15:17:38 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_new_elem(int nb)
{
	t_lst 	*elem;

	if (!(elem = (t_lst*)malloc(sizeof(t_lst))))
		exit(1);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}

t_lst	*ft_add_elem_to_end(t_lst *stack_last, t_lst *elem)
{
	stack_last->next = elem;
	return (elem);
}

int		ft_check_data(char *str)
{
	return (ft_atoi(str));
}

t_lst	*ft_params_to_list(int arg, char **argv)
{
	t_lst	*stack;
	t_lst	*stack_last;
	int		i;

	stack = ft_new_elem(ft_check_data(argv[1]));
	stack_last = stack;
	i = 2;
	while (i < arg)
	{
		stack_last = ft_add_elem_to_end(stack_last, ft_new_elem(ft_check_data(argv[i])));
		i++;
	}
	return (stack);
}