/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:31:07 by llahti            #+#    #+#             */
/*   Updated: 2020/02/19 11:47:40 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_pivot_under(t_lst *lst, int average)
{
	int		pivot;

	pivot = lst->nb;
	while (lst)
	{
		if (lst->nb == average)
			return (average);
		if (ft_abs(lst->nb - average) < ft_abs(pivot - average))
			pivot = lst->nb;
		lst = lst->next;
	}
	return (pivot);
}

int		ft_average_under(int pivot, t_lst *lst)
{
	int		sum;
	int		amount;

	sum = 0;
	amount = 0;
	while (lst)
	{
		if (lst->nb < pivot)
		{
			sum += lst->nb;
			amount++;
		}
		lst = lst->next;
	}
	return (sum / amount);
}
