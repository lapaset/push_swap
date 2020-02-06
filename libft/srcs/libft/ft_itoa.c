/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:51:19 by llahti            #+#    #+#             */
/*   Updated: 2019/10/29 18:24:20 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_if_zero(char *str)
{
	str[0] = '0';
	str[1] = 0;
	return (str);
}

static char		*ft_fillnbs(int n, char *str, int is_negative, int i)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			str[0] = '8';
			n = -214748364;
			i++;
		}
		is_negative = 1;
		n *= -1;
	}
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = 0;
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	*result;

	str = (char*)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		return (ft_if_zero(str));
	str = ft_fillnbs(n, str, 0, 0);
	result = ft_strrev(str);
	return (result);
}
