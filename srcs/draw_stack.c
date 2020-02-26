/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:59:12 by llahti            #+#    #+#             */
/*   Updated: 2020/02/26 08:53:24 by llahti           ###   ########.fr       */
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

static t_color	*ft_get_color(t_color *clr, char *color)
{
	clr = (t_color*)malloc(sizeof(t_color));
	
	clr->b = ft_get_rgb(color, 2);
	clr->g = ft_get_rgb(color, 4);
	clr->r = ft_get_rgb(color, 6);
	return (clr);
}

static t_color	*ft_negative_color(t_color *original_color)
{
	t_color	*color;

	color = (t_color*)malloc(sizeof(t_color));	
	color->b = original_color->b - 150;
	color->g = original_color->g;
	color->r = original_color->r;
	return (color);
}

static void		ft_print_layer(t_mlx *mlx, t_color *clr, int x, int below_zero)
{
	int		i;

	if (below_zero)
	{
		ft_print_layer(mlx, ft_negative_color(clr), x, 0);
		return ;
	}
	i = 0;
	while (i < mlx->column_width)
	{
		if (x + (i * 4) + 2 < WIN_HEIGHT * WIN_WIDTH * 4)
		{		//check if is outside the limits
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

void			ft_draw_stack(t_mlx *mlx, t_lst *stack, int start_x, char *color)
{
	int		layer;
	t_color *clr;
	int		i;
	int		draw_x;

	clr = NULL;
	clr = ft_get_color(clr, color);
	i = 0;
	while (stack)
	{
		layer = 0;
		while ((stack->nb > 0 && layer <= mlx->multiply * stack->nb) ||
				(stack->nb < 0 && layer < mlx->multiply * stack->nb * -1))
		{
			if (stack->nb < 0)
				draw_x = start_x * 4 + (mlx->column_width + 1) * i * 4 + WIN_WIDTH * 4 * (mlx->y_zero + layer);
			else
				draw_x = start_x * 4 + (mlx->column_width + 1) * i * 4 + WIN_WIDTH * 4 * (mlx->y_zero - layer);
			if (draw_x > 0)
				ft_print_layer(mlx, clr, draw_x, stack->nb < 0);
			layer++;
		}
		stack = stack->next;
		i++;
	}
}
