/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:49:31 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:20:35 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char		**ft_get_instructions(void)
{
	char	**instructions;

	instructions = (char**)malloc(sizeof(char*) * 11);
	instructions[0] = ft_stralloc("sa");
	instructions[1] = ft_stralloc("sb");
	instructions[2] = ft_stralloc("ss");
	instructions[3] = ft_stralloc("pa");
	instructions[4] = ft_stralloc("pb");
	instructions[5] = ft_stralloc("ra");
	instructions[6] = ft_stralloc("rb");
	instructions[7] = ft_stralloc("rr");
	instructions[8] = ft_stralloc("rra");
	instructions[9] = ft_stralloc("rrb");
	instructions[10] = ft_stralloc("rrr");
	return (instructions);
}

static void		(**ft_get_operations(void))(t_stacks*, char)
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

static void		ft_free_instructions(char **instructions)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		free(instructions[i]);
		i++;
	}
	free(instructions);
}

void			ft_do_operations(t_stacks *stacks, int visualize)
{
	void	(**operations)(t_stacks*, char);
	char	**instructions;
	char	*input;
	int		i;

	operations = ft_get_operations();
	instructions = ft_get_instructions();
	(void)visualize;
	//if (visualize)
	//	ft_visualize();
	while (get_next_line(1, &input) != 0)
	{
		i = 0;
		while (i < 11)
		{
			if (ft_strequ(instructions[i], input))
			{
				operations[i](stacks, input[ft_strlen(input) - 1]);
				break ;
			}
			i++;
		}
		if (i == 11)
			ft_error();
	}
	ft_free_instructions(instructions);
	free(operations);
}
