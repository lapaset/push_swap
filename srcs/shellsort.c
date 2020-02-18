/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:34:35 by llahti            #+#    #+#             */
/*   Updated: 2020/02/12 13:34:49 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int *ft_shell_sort(int arr[], int len)
{
	int     temp;
	int     gap;
	int     i;
	int     j;
	
	gap = len / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < len)
		{
			temp = arr[i];
			j = i;
			while (j >= gap && arr[j - gap] > temp)
			{
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
			i++;
		}
		int k = 0;
		/*while (k < len)
		{
			if (k % gap == 0)
				ft_printf("{blue}");
			ft_printf("%d ", arr[k]);
			ft_printf("{eoc}");
			k++;
		} 
		ft_printf("\n");*/
		gap /= 2;
	}
	return (arr);
}
