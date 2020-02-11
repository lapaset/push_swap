/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/11 12:52:52 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_close(t_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	ft_print_result(ptrs->stacks);
	exit(1);
}

void			ft_draw_stack(t_ptrs *ptrs, t_lst *stack, int y, int size_line)
{
	int		i;
	int		di;
	int		j;
	int		height;

	i = 0;
	while (stack)
	{
		if (stack->nb > 500)
			ft_close(ptrs);
		height = 0;
		while ((stack->nb >= 0 && height <= stack->nb) ||
				(stack->nb < 0 && height < stack->nb * -1))
		{
			if (stack->nb < 0)
				di = (i * 11) * 4 + size_line * (y + height);
			else
				di = (i * 11) * 4 + size_line * (y - height);
			j = 0;
			while (j < 10)
			{
				ptrs->data_ptr[di + (j * 4)] = mlx_get_color_value(ptrs->mlx_ptr, 255);
				//ft_printf("%d, di: %d, dy: %d\n", stack->nb, di, y);
				//ft_printf("di / size_line = %d\n", di / size_line);
				ptrs->data_ptr[di + (j * 4) + 1] =
					mlx_get_color_value(ptrs->mlx_ptr, 0);
				ptrs->data_ptr[di + (j * 4) + 2] = 
					mlx_get_color_value(ptrs->mlx_ptr, 255);
				j++;
			}
			height++;
		}
		stack = stack->next;
		i++;
	}
}

void			ft_draw(t_ptrs *ptrs)
{
	int		bpp;
	int		size_line;
	int		endian;
	
	ft_printf("here");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ptrs->data_ptr = mlx_get_data_addr(ptrs->img_ptr, &bpp, &size_line, &endian);
	ft_draw_stack(ptrs, ptrs->stacks->a, WIN_HEIGHT / 2, size_line);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr, 0, 0);
	ft_printf("draw\n");
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

/*void			ft_read_and_visualize(int fd, t_stacks *stacks)
{
	void	(**operations)(t_stacks*, char);
	char	*input;
	char	**instructions;
	int		i;

	operations = ft_operations();
	instructions = ft_instructions();
	while (get_next_line(fd, &input) != 0)
	{
		i = 0;
		//ft_printf("input: %s\n", input);
		while (i < 11)
		{
			if (ft_strequ(instructions[i], input))
			{
				operations[i](stacks, input[ft_strlen(input) - 1]);
				//reset image here
				break ;
			}
			i++;
		}
		if (i == 11)
			ft_error();
	}
	ft_free_instructions(instructions);
	free(operations);
}*/

void			ft_visualize(t_stacks *stacks)
{
	t_ptrs		*ptrs;

	ptrs = (t_ptrs*)malloc(sizeof(t_ptrs));
	ptrs->stacks = stacks;
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr =
		mlx_new_window(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	ft_draw(ptrs);
	mlx_key_hook(ptrs->win_ptr, ft_deal_key, ptrs);
	mlx_loop(ptrs->mlx_ptr);
}