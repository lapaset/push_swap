/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:20:23 by llahti            #+#    #+#             */
/*   Updated: 2019/10/23 17:20:56 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && cs1[i] == cs2[i])
		i++;
	return (cs1[i] - cs2[i]);
}
