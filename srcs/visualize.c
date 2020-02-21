/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:03:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/21 16:14:43 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void			ft_draw(t_ptrs *ptrs)
{
	/*int		bpp;
	int		size_line;
	int		endian;
	
	//ft_printf("here");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ptrs->data_ptr = mlx_get_data_addr(ptrs->img_ptr, &bpp, &size_line, &endian);*/
	ft_draw_stack(ptrs, ptrs->stacks->a, 0, "5500FF");
	ft_draw_stack(ptrs, ptrs->stacks->b, 850, "00FFFF");
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr, 0, 0);
	ft_printf("draw\n");
}

void			ft_read_and_visualize(int fd, t_stacks *stacks, t_ptrs *ptrs)
{
	void	(**operations)(t_stacks*, char);
	char	*input;
	char	**instructions;
	int		i;

	operations = ft_operations();
	instructions = ft_instructions();
	ft_draw(ptrs);
	while (get_next_line(fd, &input) != 0)
	{
		i = 0;
		//ft_printf("input: %s\n", input);
		while (i < 11)
		{
			if (ft_strequ(instructions[i], input))
			{
				operations[i](stacks, input[ft_strlen(input) - 1]);
				//destroy previous image if needed here!!
				ft_printf("%s\n", instructions[i]);
				/*if (ptrs->img_ptr)
				{
					mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
					ft_printf("img_ptr destroyed\n");
				}*/
				ft_draw(ptrs);
				break ;
			}
			i++;
		}
		if (i == 11)
			ft_error();
	}
	ft_free_instructions(instructions);
	free(operations);
	mlx_loop(ptrs->mlx_ptr);

}

void			ft_close(t_ptrs *ptrs)
{
	mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
	ft_print_result(ptrs->stacks);
	exit(1);
}

void			ft_start(t_ptrs *ptrs)
{
	ft_draw(ptrs);
	ft_read_and_visualize(0, ptrs->stacks, ptrs);
}

int				ft_deal_key(int key, t_ptrs *ptrs)
{
	ft_printf("%d\n", key);
	void	(*key_funcs[54])(t_ptrs*);
	ft_bzero(key_funcs, sizeof(void*) * 54);
	key_funcs[53] = &ft_close;
	key_funcs[49] = &ft_start;
	if (key < 54)
		key_funcs[key](ptrs);
	return (1);
}

void			ft_visualize(t_stacks *stacks)
{
	t_ptrs		*ptrs;

	ptrs = (t_ptrs*)malloc(sizeof(t_ptrs));
	ptrs->stacks = stacks;
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr =
		mlx_new_window(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Le visualizer");
	int		bpp;
	int		size_line;
	int		endian;
	
	//ft_printf("here");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	ptrs->data_ptr = mlx_get_data_addr(ptrs->img_ptr, &bpp, &size_line, &endian);
	mlx_key_hook(ptrs->win_ptr, ft_deal_key, ptrs);
	mlx_loop(ptrs->mlx_ptr);
}