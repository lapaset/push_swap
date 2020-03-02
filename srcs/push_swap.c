/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:52:52 by llahti            #+#    #+#             */
/*   Updated: 2020/03/02 08:41:40 by llahti           ###   ########.fr       */
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
		ft_sort(stacks, arg - 1);
	//ft_print_lst(stacks->a);
	//ft_print_lst(stacks->b);
	return (0);
}


//make the push_swap take strings as well