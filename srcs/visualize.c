/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/26 09:07:11 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stdio.h"

int			ft_read(t_mlx *mlx)
{
	int		i;
	char	*input;

	mlx->moves = (char**)malloc(sizeof(char*) * MAX_MOVES + 1);
	i = 0;
	while (get_next_line(0, &input) != 0)
	{
		if (i >= MAX_MOVES)
			return (-1);
		mlx->moves[i] = ft_stralloc(input);
		i++;
	}
	mlx->moves[i] = NULL;
	return (i);
}

void			ft_count_dimensions(t_mlx *mlx)
{
	mlx->column_width = WIN_WIDTH / 2 / mlx->stacks->a_len - 1;
	if (mlx->max <= 0)
		mlx->y_zero = 0;
	else if (mlx->min >= 0)
		mlx->y_zero = WIN_HEIGHT;
	else
		mlx->y_zero = WIN_HEIGHT / 2;
		//mlx->y_zero = WIN_HEIGHT  * (mlx->max) / ft_abs(mlx->max - mlx->min);
	mlx->multiply = 1;
	while ((mlx->max > 0 && mlx->y_zero - (mlx->multiply + 1) * mlx->max > 0) || 
			(mlx->min < 0 && mlx->y_zero -
			(mlx->multiply + 1) * mlx->min < WIN_HEIGHT))
		mlx->multiply++;
}

int				ft_scale(t_mlx *mlx)
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

int				ft_is_visualisable(t_mlx *mlx)
{
	//check if the amount is too big
	if (WIN_WIDTH / 2 / mlx->stacks->a_len - 1 < 2)
		ft_printf("Too many values for this window width.\n");
	else if (ft_scale(mlx) > WIN_HEIGHT - 10)
		ft_printf("Scale %d is too big to be visualized. Maximum is %d\n",
		 mlx->max - mlx->min, WIN_HEIGHT - 10);
	else if (mlx->max > WIN_HEIGHT - 10)
		ft_printf("Max value %d is too big to be visualized. Max is %d\n",
		 mlx->max, WIN_HEIGHT - 10);
	else if (mlx->min < -1 * (WIN_HEIGHT - 10))
		ft_printf("Min value %d is too small to be visualized. Min is %d\n",
		 mlx->min, WIN_HEIGHT - 10);
	else
	{
		ft_count_dimensions(mlx);
		return (1);
	}
	return (0);
}

void			ft_init_mlx(t_mlx *mlx)
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

void			ft_visualize(t_stacks *stacks)
{
	t_mlx		*mlx;
	int			moves_amount;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->stacks = stacks;
	if (!ft_is_visualisable(mlx))
	{
		//free(mlx);
		ft_deal_instructions(stacks);
		return ;
	}
	ft_init_mlx(mlx);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	moves_amount = ft_read(mlx);
	if (moves_amount == -1)
	{
		printf("Too many moves for visualization. Max is %d\n", MAX_MOVES);
		exit(1);
	}
	ft_draw_stack(mlx, mlx->stacks->a, 0, "5500FF");
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	if (moves_amount > 0)
		ft_show_moves(mlx, moves_amount);
	mlx_loop(mlx->mlx_ptr);
}
