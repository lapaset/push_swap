/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:52:52 by llahti            #+#    #+#             */
/*   Updated: 2020/02/18 10:00:03 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int arg, char **argv)
{
	t_stacks	*stacks;

	if (arg == 1)
		return (1);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	ft_params_to_list(arg, argv, stacks);
	if (!ft_list_is_sorted(stacks->a))
		ft_quicksort(stacks, arg - 1, 1);
	ft_printf("stack a: ");
	ft_print_lst(stacks->a);
	ft_printf("stack b: ");
	ft_print_lst(stacks->b);
	return (0);
}
