/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:20:24 by llahti            #+#    #+#             */
/*   Updated: 2020/02/25 12:32:47 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			ft_fill_image(t_mlx *mlx)
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

int			ft_move(t_mlx *mlx, int i)
{
	if (ft_strequ(mlx->instructions[i], mlx->moves[mlx->i]))
	{
		mlx->operations[i](mlx->stacks,
			mlx->moves[mlx->i][ft_strlen(mlx->moves[mlx->i]) - 1]);
		if (mlx->speed)
			usleep(mlx->speed);
		ft_fill_image(mlx);
		ft_draw_stack(mlx, mlx->stacks->a, 0, "5500FF");
		ft_draw_stack(mlx, mlx->stacks->b, WIN_WIDTH / 2 + 10, "00FFFF");
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
		return (1);
	}
	return (0);
}

int			ft_draw(t_mlx *mlx)
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
	//ft_free_instructions(mlx->instructions);
	//free(mlx->operations);
	return (1);
}

void			ft_show_moves(t_mlx *mlx, int moves_amount)
{
	mlx->drawn = 0;
	mlx->i = 0;
	mlx->operations = ft_operations();
	mlx->instructions = ft_instructions();
	mlx->speed = MIN_SPEED - MIN_SPEED * moves_amount / MAX_INSTRUCTIONS;
	mlx_loop_hook(mlx->mlx_ptr, ft_draw, mlx);
}