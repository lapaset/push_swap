/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/02/06 16:52:09 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_list_is_sorted(t_lst *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
	if (ft_list_is_sorted(stack))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}