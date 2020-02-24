/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/24 17:10:28 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stdio.h"

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

int			ft_draw(t_mlx *mlx)
{
	void	(**operations)(t_stacks*, char);
	char	**instructions;
	int		i;

	operations = ft_operations();
	instructions = ft_instructions();
	if (!mlx->drawn && mlx->instructions[mlx->i] != NULL)
	{
		i = 0;
		while (i < 11)
		{
			if (ft_strequ(instructions[i], mlx->instructions[mlx->i]))
			{
				operations[i](mlx->stacks, mlx->instructions[mlx->i][ft_strlen(mlx->instructions[mlx->i]) - 1]);
				if (mlx->speed)
					usleep(mlx->speed);
				ft_fill_image(mlx);
				ft_draw_stack(mlx, mlx->stacks->a, 0, "5500FF");
				ft_draw_stack(mlx, mlx->stacks->b, WIN_WIDTH / 2 + 10, "00FFFF");
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
				break ;
			}
			i++;
		}
		if (i == 11)
			ft_error();
		mlx->i++;
	}
	else
		mlx->drawn = 1;
	//ft_free_instructions(instructions);
	//free(operations);
	return (1);
}

int			ft_read(t_mlx *mlx)
{
	int		i;
	char	*input;

	mlx->instructions = (char**)malloc(sizeof(char*) * MAX_INSTRUCTIONS + 1);
	i = 0;
	//mlx->instructions[i] = (char*)malloc(sizeof(char) * 4);
	while (get_next_line(0, &input) != 0)
	{
		mlx->instructions[i] = ft_stralloc(input);
		i++;
	}
	mlx->instructions[i] = NULL;
	return (i);
}

void			ft_close(t_mlx *mlx)
{
	ft_printf("speed: %d\n", mlx->speed);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	ft_print_result(mlx->stacks);
	exit(1);
}

void			ft_start(t_mlx *mlx)
{
	mlx_loop_hook(mlx->mlx_ptr, ft_draw, mlx);
}

int				ft_deal_key(int key, t_mlx *mlx)
{
	ft_printf("%d\n", key);
	void	(*key_funcs[54])(t_mlx*);
	ft_bzero(key_funcs, sizeof(void*) * 54);
	key_funcs[53] = &ft_close;
	//key_funcs[49] = &ft_start;
	if (key < 54)
		key_funcs[key](mlx);
	return (1);
}

void			ft_count_dimensions_and_speed(t_mlx *mlx, int instructions)
{
	mlx->column_width = (WIN_WIDTH / mlx->stacks->a_len - 1) / 2;
	//todo: count zero y 
	if (mlx->max <= 0)
		mlx->y_zero = 0;
	else if (mlx->min >= 0)
		mlx->y_zero = WIN_HEIGHT;
	else
		mlx->y_zero = WIN_HEIGHT / 2;
	mlx->multiply = 1;
	while ((mlx->max > 0 && mlx->y_zero - (mlx->multiply + 1) * mlx->max > 0) || 
			(mlx->min < 0 && mlx->y_zero - (mlx->multiply + 1) * mlx->min < WIN_HEIGHT))
		mlx->multiply++;
	mlx->speed = 60000 - 60000 * instructions / MAX_INSTRUCTIONS;
}

int				ft_scale(t_mlx *mlx)
{
	t_lst	*temp;

	temp = mlx->stacks->a;
	mlx->min = temp->nb;
	mlx->max = temp->nb;
	while (temp->next)
	{
		if (temp->nb < mlx->min)
			mlx->min = temp->nb;
		if (temp->nb > mlx->max)
			mlx->max = temp->nb;
		temp = temp->next;
	}
	return (mlx->max - mlx->min);
}

void			ft_init_image(t_mlx *mlx)
{
	int		bpp;
	int		size_line;
	int		endian;

	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->data_ptr = mlx_get_data_addr(mlx->img_ptr, &bpp, &size_line, &endian);
}

void			ft_visualize(t_stacks *stacks)
{
	t_mlx		*mlx;
	int			instructions;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));
	mlx->stacks = stacks;
	mlx->drawn = 0;
	mlx->i = 0;

	//make a function to check if stack fits the visualizer
	if (ft_scale(mlx) > 990)
	{
		ft_printf("The scale is too big to be visualized. Scale is %d when maximum is 980\n", mlx->max - mlx->min);
		ft_deal_instructions(stacks);
		return ;
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr =
		mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	ft_init_image(mlx);
	mlx_key_hook(mlx->win_ptr, ft_deal_key, mlx);
	//read the instructions
	instructions = ft_read(mlx);
	ft_printf("instructions: %d\n", instructions);
	ft_count_dimensions_and_speed(mlx, instructions);
	//draw the instructions
	mlx_loop_hook(mlx->mlx_ptr, ft_draw, mlx);
	mlx_loop(mlx->mlx_ptr);
	//ft_fill_image(mlx);
}