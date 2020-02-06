/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:36:11 by llahti            #+#    #+#             */
/*   Updated: 2020/01/11 19:38:33 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_base(int is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}

void		ft_put_unsigned_base(unsigned long long nb, int base, int is_upper)
{
	char	*str;
	int		len;
	char	*basestr;
	int		i;

	if (nb == 0)
	{
		ft_putnbr(0);
		return ;
	}
	len = ft_unsigned_len(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	basestr = ft_base(is_upper);
	i = 1;
	while (nb)
	{
		str[len - i] = basestr[nb % base];
		nb /= base;
		i++;
	}
	str[len] = '\0';
	ft_putstr(str);
	free(str);
}
