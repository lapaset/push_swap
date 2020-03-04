/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_elem_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:43:29 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:34:28 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

t_lst			*ft_new_elem(int nb)
{
	t_lst	*elem;

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
