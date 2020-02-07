/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:16:19 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_to_visualize(char **argv)
{
	if (ft_strequ(argv[1], "-v"))
		return (1);
	return (0);
}

int 	main(int arg, char **argv)
{	
	t_stacks	*stacks;
	int			visualize;

	if (arg == 1)
		return (1);
	visualize = ft_to_visualize(argv);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	if (visualize)
		ft_params_to_list(arg - 1, &argv[1], stacks);
	else
		ft_params_to_list(arg, argv, stacks);
	ft_do_operations(stacks, visualize);
	ft_print_result(stacks);
	return (0);
}
	
	/*ft_printf("Stack a at beginning:");
	ft_print_lst(stacks->a);
	ft_printf("Stack b at beginning:");
	ft_print_lst(stacks->b);

	ft_swap(stacks, 'a');
	ft_printf("Stack a after swap a:");
	ft_print_lst(stacks->a);
	ft_printf("Stack b after swap a:");
	ft_print_lst(stacks->b);

	ft_push(stacks, 'b');
	ft_printf("Stack a after push b:");
	ft_print_lst(stacks->a);
	ft_printf("Stack b after push b:");
	ft_print_lst(stacks->b);

	ft_rotate(stacks, 'a');
	ft_printf("Stack a after rotate a:");
	ft_print_lst(stacks->a);
	ft_printf("Stack b after rotate a:");
	ft_print_lst(stacks->b);

	ft_reverse_rotate(stacks, 'r');
	ft_printf("Stack a after reverse rotate r:");
	ft_print_lst(stacks->a);
	ft_printf("Stack b after reverse rotate r:");
	ft_print_lst(stacks->b);*/