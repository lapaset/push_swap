/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:57:28 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_draw()
{
	ft_printf("draw\n");
}

void			ft_close(t_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	ft_print_result(ptrs->stacks);
	exit(1);
}

int				ft_deal_key(int key, t_ptrs *ptrs)
{
	ft_printf("%d\n", key);
	void	(*key_funcs[54])(t_ptrs*);

	ft_bzero(key_funcs, sizeof(void*) * 54);
	key_funcs[53] = &ft_close;
	//key_funcs[18] = &ft_swap;
	key_funcs[key](ptrs);
	return (1);
}

void			ft_visualize(t_stacks *stacks)
{
	t_ptrs		*ptrs;

	ptrs = (t_ptrs*)malloc(sizeof(t_ptrs));
	ptrs->stacks = stacks;
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr =
		mlx_new_window(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	mlx_key_hook(ptrs->win_ptr, ft_deal_key, ptrs);
	mlx_loop(ptrs->mlx_ptr);
}