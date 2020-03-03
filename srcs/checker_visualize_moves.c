/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_visualize_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:20:24 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 15:23:05 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_fill_image(t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH * 4)
	{
		mlx->data_ptr[i] = mlx_get_color_value(mlx->mlx_ptr, 0);
		i++;
		mlx->data_ptr[i] = mlx_get_color_value(mlx->mlx_ptr, 0);
		i++;
		mlx->data_ptr[i] = mlx_get_color_value(mlx->mlx_ptr, 0);
		i++;
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (1);
}

static int	ft_move(t_mlx *mlx, int i)
{
	if (ft_strequ(mlx->instructions[i], mlx->moves[mlx->i]))
	{
		mlx->operations[i](mlx->stacks,
			mlx->moves[mlx->i][ft_strlen(mlx->moves[mlx->i]) - 1]);
		if (mlx->speed)
			usleep(mlx->speed);
		ft_fill_image(mlx);
		ft_draw_stack(mlx, mlx->stacks->a, 0, STACK_A_COLOR);
		ft_draw_stack(mlx, mlx->stacks->b, WIN_WIDTH / 2, STACK_B_COLOR);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		return (1);
	}
	return (0);
}

static int	ft_draw(t_mlx *mlx)
{
	int		i;

	if (!mlx->drawn && mlx->moves[mlx->i] != NULL)
	{
		i = 0;
		while (i < 11)
		{
			if (ft_move(mlx, i))
				break ;
			i++;
		}
		if (i == 11)
			ft_error();
		mlx->i++;
	}
	else
		mlx->drawn = 1;
	return (1);
}

void		ft_visualize_moves(t_mlx *mlx, int moves_amount)
{
	mlx->drawn = 0;
	mlx->i = 0;
	if (moves_amount > 300)
		mlx->speed = 0;
	else
		mlx->speed = MIN_SPEED - MIN_SPEED * moves_amount / 300;
	mlx_loop_hook(mlx->mlx_ptr, ft_draw, mlx);
}
