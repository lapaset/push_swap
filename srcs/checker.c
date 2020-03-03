/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:47:58 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 15:24:48 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int 	main(int arg, char **argv)
{	
	t_stacks	*stacks;
	t_mlx		*mlx;
	t_flags		*flags;
	int			i;

	if (arg == 1)
		return (1);
	flags = (t_flags*)malloc(sizeof(t_flags));
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	i = ft_add_checker_flags(arg, argv, flags);
	ft_params_to_list(arg - i + 1, &argv[i - 1], stacks);
	mlx = NULL;
	if (flags->v)
	{
		mlx = (t_mlx*)malloc(sizeof(t_mlx));
		ft_copy_stacks_to_mlx(mlx, stacks);
	}
	ft_deal_instructions(stacks, flags, mlx);
	ft_print_result(stacks, flags->d);
	if (flags->v)
		ft_visualize(mlx);
	return (0);
}
