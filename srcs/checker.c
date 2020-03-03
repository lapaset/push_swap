/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 10:37:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_is_checker_flag(char *argv)
{
	//ft_printf("is_checker_flag? %s\n", argv);
	return (ft_strnequ(argv, "-v", 2) || ft_strnequ(argv, "-e", 2) ||
		ft_strnequ(argv, "-d", 2));
}
void	ft_add_checker_flags(int arg, char **argv, t_flags *flags)
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

void	ft_make_list(int arg, char **argv, t_stacks *stacks, t_flags *flags)
{
	int		i;

	ft_add_checker_flags(arg, argv, flags);
	i = 1;
	while (i < arg && ft_is_checker_flag(argv[i]))
			i++;
	//ft_printf("arg - i: %d argv[i]: %s\n", arg - i, argv[i]);
	ft_params_to_list(arg - i + 1, &argv[i - 1], stacks);
	//ft_print_lst(stacks->a);
	//ft_printf("a_len: %d", stacks->a_len);
}

void		ft_print_result(t_stacks *stacks, int d)
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

int 	main(int arg, char **argv)
{	
	t_stacks	*stacks;
	t_mlx		*mlx = NULL;
	t_flags		*flags;

	if (arg == 1)
		return (1);
	flags = (t_flags*)malloc(sizeof(t_flags));
	ft_add_checker_flags(arg, argv, flags);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	ft_make_list(arg, argv, stacks, flags);
	if (flags->v)
	{
		mlx = (t_mlx*)malloc(sizeof(t_mlx));
		ft_copy_stacks_to_mlx(mlx, stacks);
	}
	if (!ft_deal_instructions(stacks, flags, mlx))
	{
		ft_printf("Too many moves for visualization. Max is %d\n", MAX_MOVES);
		flags->v = 0;
	}
	ft_print_result(stacks, flags->d);
	if (flags->v)
		ft_visualize(mlx);
	return (0);
}
