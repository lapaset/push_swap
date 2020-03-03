/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 15:22:54 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_count_dimensions(t_mlx *mlx)
{
	mlx->column_width = WIN_WIDTH / 2 / mlx->stacks->a_len - 1;
	if (mlx->max <= 0)
		mlx->y_zero = 0;
	else if (mlx->min >= 0)
		mlx->y_zero = WIN_HEIGHT;
	else
		mlx->y_zero = WIN_HEIGHT * ft_abs(mlx->max) / (mlx->max - mlx->min);
	mlx->multiply = 1;
	while ((mlx->max > 0 && mlx->y_zero - (mlx->multiply + 1) * mlx->max > 0) ||
			(mlx->min < 0 && mlx->y_zero -
			(mlx->multiply + 1) * mlx->min < WIN_HEIGHT))
		mlx->multiply++;
}

static int	ft_scale(t_mlx *mlx)
{
	t_lst	*temp;

	temp = mlx->stacks->a;
	mlx->min = temp->nb;
	mlx->max = temp->nb;
	while (temp)
	{
		if (temp->nb < mlx->min)
			mlx->min = temp->nb;
		if (temp->nb > mlx->max)
			mlx->max = temp->nb;
		temp = temp->next;
	}
	return (mlx->max - mlx->min);
}

static int	ft_is_visualisable(t_mlx *mlx)
{
	if (WIN_WIDTH / 2 / mlx->stacks->a_len - 1 < 1)
		ft_printf("Too many values for this window width.\n");
	else if (ft_scale(mlx) > WIN_HEIGHT - 1)
		ft_printf("Scale %d is too big to be visualized. Maximum is %d\n",
		mlx->max - mlx->min, WIN_HEIGHT - 1);
	else if (mlx->max > WIN_HEIGHT - 1)
		ft_printf("Max value %d is too big to be visualized. Max is %d\n",
		mlx->max, WIN_HEIGHT - 1);
	else if (mlx->min < -1 * (WIN_HEIGHT - 1))
		ft_printf("Min value %d is too small to be visualized. Min is %d\n",
		mlx->min, -1 * (WIN_HEIGHT - 1));
	else
	{
		ft_count_dimensions(mlx);
		return (1);
	}
	return (0);
}

static void	ft_init_mlx(t_mlx *mlx)
{
	int		bpp;
	int		size_line;
	int		endian;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr =
		mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->data_ptr = mlx_get_data_addr(mlx->img_ptr, &bpp, &size_line, &endian);
}

void		ft_visualize(t_mlx *mlx)
{
	if (!ft_is_visualisable(mlx))
		return ;
	ft_init_mlx(mlx);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	ft_draw_stack(mlx, mlx->stacks->a, 0, STACK_A_COLOR);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (mlx->moves_amount > 0)
		ft_visualize_moves(mlx, mlx->moves_amount);
	mlx_loop(mlx->mlx_ptr);
}
