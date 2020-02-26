/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:24:02 by llahti            #+#    #+#             */
/*   Updated: 2020/02/25 15:37:41 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_close(t_mlx *mlx)
{
	//ft_printf("speed: %d\n", mlx->speed);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_print_result(mlx->stacks);
	//ft_print_lst(mlx->stacks->a);
	exit(1);
}

int				ft_deal_key(int key, t_mlx *mlx)
{
	//ft_printf("%d\n", key);
	void	(*key_funcs[54])(t_mlx*);
	ft_bzero(key_funcs, sizeof(void*) * 54);
	key_funcs[53] = &ft_close;
	if (key < 54)
		key_funcs[key](mlx);
	return (1);
}
