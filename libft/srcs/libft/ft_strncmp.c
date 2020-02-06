/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:43:24 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 12:34:55 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (*c1 != 0 && *c1 == *c2 && i < n - 1)
	{
		c1++;
		c2++;
		i++;
	}
	return (*c1 - *c2);
}
