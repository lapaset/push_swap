/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:12:53 by llahti            #+#    #+#             */
/*   Updated: 2019/10/24 14:52:18 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *str;
	char *last;

	last = NULL;
	str = (char*)s;
	while (*str != 0)
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (*str == c)
		last = str;
	return (last);
}
