/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 13:24:40 by llahti            #+#    #+#             */
/*   Updated: 2020/01/10 13:51:07 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_ll_len(long long nb)
{
	int					len;
	unsigned long long	usnb;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	usnb = (unsigned long long)nb;
	while (usnb > 9)
	{
		len++;
		usnb /= 10;
	}
	return (len);
}
