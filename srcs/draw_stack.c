/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:59:12 by llahti            #+#    #+#             */
/*   Updated: 2020/02/27 17:24:08 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_get_rgb(char *color, int minlen)
{
	int		temp;
	int		res;
	int		len;

	len = ft_hexa_len(color);
	if (len < minlen)
		return (0);
	res = ft_hexa_to_int(color[len - minlen + 1]);
	temp = ft_hexa_to_int(color[len - minlen]);
	return (res + temp * 16);
}

static t_color	*ft_get_color(char *color, int nb)
{
	t_color		*clr;

	clr = (t_color*)malloc(sizeof(t_color));
	if (nb > 0)
		clr->b = ft_get_rgb(color, 2);
	else
		clr->b = ft_get_rgb(color, 2) - 150;
	clr->g = ft_get_rgb(color, 4);
	clr->r = ft_get_rgb(color, 6);
	return (clr);
}

static void		ft_print_layer(t_mlx *mlx, t_color *clr, int x)
{
	int		i;

	i = 0;
	while (i < mlx->column_width)
	{
		if (x + (i * 4) + 2 < WIN_HEIGHT * WIN_WIDTH * 4)
		{
			mlx->data_ptr[x + (i * 4)] =
				mlx_get_color_value(mlx->mlx_ptr, clr->r);
			mlx->data_ptr[x + (i * 4) + 1] =
				mlx_get_color_value(mlx->mlx_ptr, clr->g);
			mlx->data_ptr[x + (i * 4) + 2] =
				mlx_get_color_value(mlx->mlx_ptr, clr->b);
		}
		i++;
	}
}

static void		ft_print_column(t_lst *stack, t_mlx *mlx, int start_x,
				char *color)
{
	int			layer;
	int			draw_x;
	t_color		*clr;

	if (stack->nb == 0)
		return ;
	clr = ft_get_color(color, stack->nb);
	layer = 0;
	while ((stack->nb > 0 && layer <= mlx->multiply * stack->nb) ||
			(stack->nb < 0 && layer < mlx->multiply * stack->nb * -1))
	{
		if (stack->nb < 0)
			draw_x = start_x + WIN_WIDTH * 4 * (mlx->y_zero + layer);
		else
			draw_x = start_x + WIN_WIDTH * 4 * (mlx->y_zero - layer);
		if (draw_x > 0)
			ft_print_layer(mlx, clr, draw_x);
		layer++;
	}
	free(clr);
}

void			ft_draw_stack(t_mlx *mlx, t_lst *stack, int start_x,
				char *color)
{
	int			i;

	i = 0;
	while (stack)
	{
		ft_print_column(stack, mlx,
						start_x * 4 + (mlx->column_width + 1) * i * 4, color);
		stack = stack->next;
		i++;
	}
}
