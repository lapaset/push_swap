/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:21:06 by llahti            #+#    #+#             */
/*   Updated: 2019/10/23 10:20:04 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*space;
	size_t	i;

	space = (char*)malloc(size);
	if (space)
	{
		i = 0;
		while (i < size)
		{
			space[i] = 0;
			i++;
		}
	}
	return ((void*)space);
}
