/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:13:09 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 11:54:05 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int a;
	int sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' | *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	a = 0;
	while (ft_isdigit(*str))
	{
		a = a * 10 + (*str - 48);
		str++;
	}
	return (a * sign);
}
