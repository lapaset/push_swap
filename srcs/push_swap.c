/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:52:52 by llahti            #+#    #+#             */
/*   Updated: 2020/03/04 16:25:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(t_stacks *stacks)
{
	int			*arr;
	int			i;

	arr = (int*)malloc(sizeof(int) * stacks->a_len);
	arr[0] = ft_find_the_smallest(stacks->a);
	i = 1;
	while (i < stacks->a_len)
	{
		arr[i] = ft_find_next_smallest(stacks->a, arr[i - 1]);
		i++;
	}
	if (stacks->a_len == 3)
		ft_sort_a_of_three(stacks);
	else if (stacks->a_len < 20)
		ft_small_sort(stacks, arr);
	else if (stacks->a_len < 200)
		ft_combine_sort(stacks, arr);
	else
		ft_quicksort(stacks, stacks->a_len, 1, arr);
	free(arr);
}

int			main(int arg, char **argv)
{
	t_stacks	*stacks;

	if (arg == 1)
		return (1);
	stacks = (t_stacks*)malloc(sizeof(t_stacks));
	ft_params_to_list(arg, argv, stacks);
	if (!ft_is_basically_sorted(stacks, ft_find_the_smallest(stacks->a),
		ft_find_the_biggest(stacks->a)))
		ft_sort(stacks);
	return (0);
}
