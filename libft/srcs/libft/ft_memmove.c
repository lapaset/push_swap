/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:30:06 by llahti            #+#    #+#             */
/*   Updated: 2019/10/29 16:38:18 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	unsigned char	tmp[len];
	size_t			i;

	if (len > 0 && !dst && !src)
		return (NULL);
	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		tmp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cdst[i] = tmp[i];
		i++;
	}
	return (cdst);
}
