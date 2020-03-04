/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_read_instructions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:36:35 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 12:29:06 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_read_and_do(int fd, t_stacks *stacks, t_flags *flags)
{
	void	(**operations)(t_stacks*, char);
	char	*input;
	char	**instructions;

	operations = g_ft_operations();
	instructions = ft_instructions();
	while (get_next_line(fd, &input) != 0)
	{
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

int		ft_get_mlx_moves(t_mlx *mlx, t_stacks *stacks)
{
	int		i;
	char	*input;

	i = 0;
	while (get_next_line(0, &input) != 0)
	{
		if (!input[0])
			break ;
		mlx->operations[ft_instruction_nb(input, mlx->instructions)](stacks,
		input[ft_strlen(input) - 1]);
		if (i < MAX_MOVES)
			mlx->moves[i] = ft_stralloc(input);
		free(input);
		i++;
	}
	mlx->moves[i] = NULL;
	free(input);
	return (i);
}

void	ft_read_to_mlx(t_mlx *mlx, t_stacks *stacks, t_flags *flags)
{
	int		moves_amount;

	mlx->operations = g_ft_operations();
	mlx->instructions = ft_instructions();
	mlx->moves = (char**)malloc(sizeof(char*) * MAX_MOVES + 1);
	moves_amount = ft_get_mlx_moves(mlx, stacks);
	if ((mlx->moves_amount = moves_amount) > MAX_MOVES)
	{
		ft_printf("Too many moves for visualization. Max is %d\n", MAX_MOVES);
		flags->v = 0;
	}
}
