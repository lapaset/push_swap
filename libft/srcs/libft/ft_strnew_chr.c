/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:40:31 by llahti            #+#    #+#             */
/*   Updated: 2019/11/20 11:47:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_chr(size_t size, char c)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(size + 1);
	if (str)
	{
		i = 0;
		while (i < size)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
