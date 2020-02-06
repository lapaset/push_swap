/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:09:06 by llahti            #+#    #+#             */
/*   Updated: 2019/10/28 17:58:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	if (len == 0)
		return (dst);
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		if (src[j] != 0)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		else
		{
			dst[i] = 0;
			i++;
		}
	}
	dst[i] = src[j];
	return (dst);
}
