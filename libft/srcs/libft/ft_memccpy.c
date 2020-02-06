/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:29:59 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 11:56:17 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	unsigned char	uc;
	size_t			i;

	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*tmpdst = tmpsrc[i];
		tmpdst++;
		if (tmpsrc[i] == uc)
			return (tmpdst);
		i++;
	}
	return (NULL);
}
