/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:23:37 by llahti            #+#    #+#             */
/*   Updated: 2020/03/01 10:29:39 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_if_first_is_bigger(t_stacks *stacks, char c)
{
	if (stacks->a->nb > stacks->a->next->nb)
		ft_psswap(stacks, c);
}

void		ft_sort_a_of_three(t_stacks *stacks)
{
	if (ft_list_is_sorted(stacks->a))
		//123
		return ;
	else if (stacks->a->nb > stacks->a->next->nb &&
		stacks->a->nb > stacks->a->next->next->nb)
	{
		//321 312
		ft_psrotate(stacks, 'a');
		ft_swap_if_first_is_bigger(stacks, 'a');
	}
	else if (stacks->a->nb > stacks->a->next->nb)
		//213
		ft_psswap(stacks, 'a');
	else if (stacks->a->nb < stacks->a->next->next->nb)  
	{
		//132
		ft_psrotate(stacks, 'a');
		ft_psswap(stacks, 'a');
		ft_psreverse_rotate(stacks, 'a');
	}
	else
		//231
		ft_psreverse_rotate(stacks, 'a');
}

void		ft_sort(t_stacks *stacks, int amount)
{
	if (ft_is_basically_sorted(stacks, ft_find_the_smallest(stacks->a),
		ft_find_the_biggest(stacks->a)))
		return ;
	if (amount == 3)
		ft_sort_a_of_three(stacks);
	else if (amount < 20)
		ft_small_sort(stacks);
	else if (amount < 200)
		ft_combine_sort(stacks);
	else
		ft_quicksort(stacks, amount, 1);
}

//combine sort: ./average.sh -100 500 500 100 Average is 9558
//quicksort: ./average.sh -100 500 500 100 Average is 5781
//small sort averages:
// 4: 6		5
// 5: 8		7
// 6: 11	10	
// 7: 13	13
// 8: 17	17
// 15: 44	45	46
// 20: 66	67	67
// 25: 92	94	91
// 29: 116	117	111