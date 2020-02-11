/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:59:12 by llahti            #+#    #+#             */
/*   Updated: 2020/02/11 17:54:43 by llahti           ###   ########.fr       */
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

static void		ft_print_layer(t_ptrs *ptrs, t_color *clr, int x)
{
	int		i;


	i = 0;
	while (i < 10)
	{
		//ft_printf("here");
		ptrs->data_ptr[x + (i * 4)] =
			mlx_get_color_value(ptrs->mlx_ptr, clr->r);
		ptrs->data_ptr[x + (i * 4) + 1] =
			mlx_get_color_value(ptrs->mlx_ptr, clr->g);
		ptrs->data_ptr[x + (i * 4) + 2] = 
			mlx_get_color_value(ptrs->mlx_ptr, clr->b);
		i++;
	}
}

void			ft_draw_stack(t_ptrs *ptrs, t_lst *stack, int start, char *color)
{
	int		layer;
	t_color *clr;
	int		i;
	int		draw;

	clr = NULL;
	clr = ft_get_color(clr, color);
	i = 0;
	while (stack)
	{
		if (stack->nb > 400)
			ft_close(ptrs);
		layer = 0;
		while ((stack->nb >= 0 && layer <= stack->nb) ||
				(stack->nb < 0 && layer < stack->nb * -1))
		{
			if (stack->nb < 0)
				draw = start * 4 + 11 * i * 4 + WIN_WIDTH * 4 * (WIN_HEIGHT / 2 + layer);
			else
				draw = start * 4 + 11 * i * 4 + WIN_WIDTH * 4 * (WIN_HEIGHT / 2 - layer);
			if (draw > 0)
				ft_print_layer(ptrs, clr, draw);
			layer++;
		}
		ft_printf("nb: %d, ", stack->nb);
		stack = stack->next;
		i++;
	}
}
