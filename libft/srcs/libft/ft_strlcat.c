/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:11:30 by llahti            #+#    #+#             */
/*   Updated: 2019/10/23 17:33:31 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char*)src);
	if (dstsize == 0 | dstsize < dstlen)
		return (srclen + dstsize);
	i = 0;
	while (dstlen + i < dstsize - 1 && src[i] != 0)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
