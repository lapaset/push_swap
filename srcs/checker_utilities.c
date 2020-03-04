/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:31:03 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 11:59:06 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_result(t_stacks *stacks, int d)
{
	if (ft_list_is_sorted(stacks->a) && stacks->b == NULL)
		ft_putendl("OK");
	else
	{
		ft_putendl("KO");
		if (d)
		{
			ft_printf("Stack a: ");
			ft_print_lst(stacks->a);
			ft_printf("Stack b: ");
			ft_print_lst(stacks->b);
		}
	}
}

int		ft_is_checker_flag(char *argv)
{
	return (ft_strnequ(argv, "-v", 2) || ft_strnequ(argv, "-e", 2) ||
		ft_strnequ(argv, "-d", 2));
}

int		ft_add_checker_flags(int arg, char **argv, t_flags *flags)
{
	int		i;
	int		j;

	i = 1;
	flags->v = 0;
	flags->d = 0;
	flags->e = 0;
	while (i < arg && ft_is_checker_flag(argv[i]))
	{
		j = 1;
		if (argv[i][j] == 'v')
			flags->v = 1;
		if (argv[i][j] == 'd')
			flags->d = 1;
		if (argv[i][j] == 'e')
			flags->e = 1;
		i++;
	}
	return (i);
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
