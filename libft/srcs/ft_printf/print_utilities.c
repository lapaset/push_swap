/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:09:21 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 13:05:54 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_has_flag(t_convs *convs, char flag)
{
	if (ft_strchr(convs->flags, flag))
		return (1);
	return (0);
}

int		ft_get_base(t_convs *convs)
{
	if (convs->specifier == 'u')
		return (10);
	if (convs->specifier == 'o')
		return (8);
	if (convs->specifier == 'x' || convs->specifier == 'X')
		return (16);
	if (convs->specifier == 'b')
		return (2);
	return (-1);
}

void	ft_put_blanks(int amount)
{
	ft_put_chars(amount, ' ');
}

void	ft_put_zeros(int amount)
{
	ft_put_chars(amount, '0');
}

int		ft_zero_zero(t_convs *convs)
{
	int		blanks;

	blanks = convs->min_width;
	if ((convs->specifier == 'o' && ft_has_flag(convs, '#')) ||
		((convs->specifier == 'd' || convs->specifier == 'i')
		&& ft_has_flag(convs, '+')))
	{
		if (!ft_is_left_oriented(convs))
			ft_put_blanks(blanks - 1);
		if (convs->specifier == 'o')
			ft_putchar('0');
		else
			ft_putchar('+');
		if (ft_is_left_oriented(convs))
			ft_put_blanks(blanks - 1);
		if (blanks > 1)
			return (blanks);
		return (1);
	}
	if (blanks <= 0)
		return (0);
	ft_put_blanks(blanks);
	return (blanks);
}
