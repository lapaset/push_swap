/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:49:31 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 15:49:43 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		**ft_instructions(void)
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

void		ft_free_instructions(char **instructions)
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

int			ft_instruction_nb(char *input, char **instructions)
{
	int		i;

	i = 0;
	while (i < 11)
	{
		if (ft_strequ(instructions[i], input))
			break ;
		i++;
	}
	if (i == 11)
		ft_error();
	return (i);
}

int			ft_deal_instructions(t_stacks *stacks, int visualize, t_mlx *mlx)
{
	if (!visualize)
	{
		ft_read_and_do(0, stacks);
		ft_read_and_do(1, stacks);
		return (1);
	}
	return (ft_read_to_mlx(mlx, stacks));
}
