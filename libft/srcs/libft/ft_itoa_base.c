/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:16:58 by llahti            #+#    #+#             */
/*   Updated: 2020/01/08 13:49:16 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long value, int base)
{
	int					len;
	unsigned long long	nb;

	len = 0;
	if (value < 0 && base != 10)
	{
		nb = (unsigned long long)value;
		while (nb)
		{
			len++;
			nb /= base;
		}
	}
	else
	{
		while (value)
		{
			len++;
			value /= base;
		}
		if (value < 0 && base == 10)
			len++;
	}
	return (len);
}

static char	*ft_str(char *b, int len, long long value, int base)
{
	char				*str;
	long				nb;

	nb = value;
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str[len] = '\0';
	while (nb)
	{
		len--;
		str[len] = b[nb % base];
		nb /= base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}

static char	*ft_base(int is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

char		*ft_itoa_base(long long value, int base, int is_upper)
{
	int					len;
	unsigned long long	nb;
	char				*str;

	str = NULL;
	if (value == 0)
		return ("0");
	if (value < 0 && base != 10)
	{
		nb = (unsigned long long)value;
		len = ft_len(value, base);
		str = ft_str(ft_base(is_upper), len, nb, base);
	}
	else
	{
		len = ft_len(value, base);
		str = ft_str(ft_base(is_upper), len, value, base);
	}
	return (str);
}
