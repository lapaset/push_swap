/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 17:11:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_visualize()
{
	t_ptrs		*ptrs;

	ptrs = (t_ptrs*)malloc(sizeof(t_ptrs));
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr =
		mlx_new_window(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	mlx_loop(ptrs->mlx_ptr);
}