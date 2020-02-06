/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:48:00 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 12:14:46 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	uc;
	size_t			i;

	cs = (unsigned char*)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*cs == uc)
			return ((void*)cs);
		cs++;
		i++;
	}
	return (NULL);
}
