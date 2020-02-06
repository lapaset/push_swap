/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:57:03 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:09:28 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_must_roundup(long double nb)
{
	nb /= 10;
	nb -= (long long)nb;
	nb *= 10;
	return (nb > 5);
}

static char	*ft_roundup_nines(char *str, int i)
{
	str[i + 2] = '\0';
	while (i >= 0 && (str[i] == '9' || str[i] == '.'))
	{
		if (str[i] == '.')
			str[i + 1] = '.';
		else
			str[i + 1] = '0';
		i--;
	}
	if (i == -1)
		str[0] = '1';
	else
	{
		str[i + 1] = str[i] + 1;
		while (i > 0)
		{
			i--;
			str[i + 1] = str[i];
		}
		str++;
	}
	return (str);
}

static char	*ft_roundup(char *str, int i, long double nb)
{
	if (!ft_must_roundup(nb))
		return (str);
	i--;
	if (str[i] != '9')
	{
		str[i]++;
		return (str);
	}
	return (ft_roundup_nines(str, i));
}

static char	*ft_make_str(t_convs *convs, int len, long double nb)
{
	char		*str;
	int			i;

	if (!(str = (char*)malloc(len + convs->precision + 3)))
		exit(1);
	i = 0;
	while (i < len + convs->precision)
	{
		if (i == len && (convs->precision != 0 || ft_has_flag(convs, '#')))
		{
			str[i] = '.';
			i++;
			len++;
		}
		str[i] = '0' + (long long)nb % 10;
		nb *= 10;
		i++;
	}
	if (convs->precision == 0 && ft_has_flag(convs, '#'))
	{
		str[i] = '.';
		i++;
	}
	str[i] = '\0';
	return (ft_roundup(str, i, nb));
}

char		*ft_double_to_str(long double nb, t_convs *convs)
{
	int			len;

	len = ft_ll_len((long long)nb);
	if (nb <= -1)
		len--;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
		nb /= 10;
	return (ft_make_str(convs, len, nb));
}
