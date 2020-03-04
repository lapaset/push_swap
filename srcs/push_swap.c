/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:52:52 by llahti            #+#    #+#             */
/*   Updated: 2020/03/03 20:47:11 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort(t_stacks *stacks, int amount)
{
	int		*arr;

	arr = (int*)malloc(sizeof(int) * amount);
	arr[0] = ft_find_the_smallest(stacks->a);
	int i = 1;
	while (i < amount)
	{
		arr[i] = ft_find_next_smallest(stacks->a, arr[i - 1]);
		i++;
	}
	i = 0;
	while (i < amount)
	{
		//ft_printf("{yellow}%d {eoc}", arr[i]);
		i++;
	}
	if (amount == 3)
		ft_sort_a_of_three(stacks);
	else if (amount < 20)
		ft_small_sort(stacks);
	else if (amount < 200)
		ft_combine_sort(stacks);
	else
		ft_quicksort(stacks, amount, 1);
}

int		main(int arg, char **argv)
{
	t_stacks	*stacks;

	if (arg == 1)
		return (1);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	ft_params_to_list(arg, argv, stacks);
	if (!ft_is_basically_sorted(stacks, ft_find_the_smallest(stacks->a),
		ft_find_the_biggest(stacks->a)))
		ft_sort(stacks, arg - 1);
	return (0);
}
