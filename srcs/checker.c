/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/02/06 16:42:06 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	main(int arg, char **argv)
{	
	t_lst	*stack;
	char	*input;

	if (arg == 1)
		return (1);
	stack = ft_params_to_list(arg, argv);
	ft_print_lst(stack);
	while (get_next_line(1, &input) != 0)
		ft_printf("%s\n", input);
	return (0);
}