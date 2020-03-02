/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:36:35 by llahti            #+#    #+#             */
/*   Updated: 2020/03/02 14:40:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_read_and_do(int fd, t_stacks *stacks, t_flags *flags)
{
	void	(**operations)(t_stacks*, char);
	char	*input;
	char	**instructions;

	operations = ft_operations();
	instructions = ft_instructions();
	while (get_next_line(fd, &input) != 0)
	{
		//ft_printf("flags->e: %d input[0]: %s$", flags->e, input[0]);
		if (flags->e && !input[0])
			break ;
		operations[ft_instruction_nb(input, instructions)](stacks,
		input[ft_strlen(input) - 1]);
		free(input);
	}
	ft_free_instructions(instructions);
	free(operations);
	free(input);
}

int		ft_read_to_mlx(t_mlx *mlx, t_stacks *stacks)
{
	int		i;
	char	*input;
	int		to_return;

	to_return = 1;
	mlx->operations = ft_operations();
	mlx->instructions = ft_instructions();
	mlx->moves = (char**)malloc(sizeof(char*) * MAX_MOVES + 1);
	i = 0;
	while (get_next_line(0, &input) != 0)
	{
		if (!input[0])
			break ;
		mlx->operations[ft_instruction_nb(input, mlx->instructions)](stacks,
		input[ft_strlen(input) - 1]);
		if (i < MAX_MOVES)
			mlx->moves[i] = ft_stralloc(input);
		else if (i == MAX_MOVES)
			to_return = 0;
		free(input);
		i++;
	}
	mlx->moves[i] = NULL;
	mlx->moves_amount = i;
	free(input);
	return (to_return);
}
