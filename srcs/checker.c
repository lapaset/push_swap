/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 15:11:05 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// todo as a bonus: with some flag enter ends giving instructions
int		ft_to_visualize(char **argv)
{
	if (ft_strequ(argv[1], "-v"))
		return (1);
	return (0);
}

void	ft_copy_stacks_to_mlx(t_mlx *mlx, t_stacks *stacks)
{
	t_lst	*temp;

	mlx->stacks = (t_stacks*)malloc(sizeof(t_stacks));
	mlx->stacks->a_len = stacks->a_len;
	mlx->stacks->b_len = 0;
	mlx->stacks->a = ft_new_elem(stacks->a->nb);
	mlx->stacks->a_end = mlx->stacks->a;
	mlx->stacks->b = NULL;
	mlx->stacks->b_end = NULL;
	temp = stacks->a->next;
	while (temp)
	{
		mlx->stacks->a_end = ft_add_elem_to_end(mlx->stacks->a_end,
								ft_new_elem(temp->nb));
		temp = temp->next;
	}
}

int 	main(int arg, char **argv)
{	
	t_stacks	*stacks;
	t_mlx		*mlx;
	int			visualize;

	if (arg == 1)
		return (1);
	mlx = NULL;
	visualize = ft_to_visualize(argv);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	if (!visualize)
		ft_params_to_list(arg, argv, stacks);
	else
	{
		ft_params_to_list(arg - 1, &argv[1], stacks);
		mlx = (t_mlx*)malloc(sizeof(t_mlx));
		ft_copy_stacks_to_mlx(mlx, stacks);
	}
	if (!ft_deal_instructions(stacks, visualize, mlx))
	{
		ft_printf("Too many moves for visualization. Max is %d\n", MAX_MOVES);
		visualize = 0;
	}
	if (visualize)
	{
		ft_print_result(stacks);
		ft_visualize(mlx);
	}
	else
		ft_print_result(stacks);
	return (0);
}
