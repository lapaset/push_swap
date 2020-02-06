/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:48:48 by llahti            #+#    #+#             */
/*   Updated: 2020/01/10 14:33:39 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_cast_to_ll(va_list args, int length_mod)
{
	int			i;
	char		hh;
	short		h;
	long		l;

	if (length_mod == 0)
		i = va_arg(args, int);
	if (length_mod == 1)
		hh = va_arg(args, int);
	if (length_mod == 2)
		h = va_arg(args, int);
	if (length_mod == 3)
		l = va_arg(args, long);
	if (length_mod == 4)
		return (va_arg(args, long long));
	if (length_mod == 0)
		return ((long long)i);
	if (length_mod == 1)
		return ((long long)hh);
	if (length_mod == 2)
		return ((long long)h);
	if (length_mod == 3)
		return ((long long)l);
	return (-1);
}

static int			ft_count_zeros_di(t_convs *convs, long long nb, char sign)
{
	int			zeros;

	if (convs->precision != -1)
	{
		zeros = convs->precision - ft_ll_len(nb);
		if (nb < 0)
			zeros++;
	}
	else if (ft_has_flag(convs, '0'))
	{
		zeros = convs->min_width - ft_ll_len(nb);
		if (nb >= 0 && sign)
			zeros--;
	}
	else
		return (0);
	if (zeros < 0)
		return (0);
	return (zeros);
}

static int			ft_count_blanks_di(t_convs *convs, int zeros,
					long long nb, char sign)
{
	int			blanks;

	if (convs->min_width == -1)
		return (0);
	blanks = convs->min_width - ft_ll_len(nb) - zeros;
	if (nb >= 0 && sign)
		blanks--;
	if (blanks < 0)
		return (0);
	return (blanks);
}

static char			ft_get_sign(t_convs *convs, long long nb)
{
	if (nb < 0)
		return ('-');
	if (ft_has_flag(convs, '+'))
		return ('+');
	if (ft_has_flag(convs, ' '))
		return (' ');
	return (0);
}

int					ft_print_di(t_convs *convs, va_list args)
{
	long long	nb;
	int			zeros;
	int			blanks;
	char		sign;

	nb = ft_cast_to_ll(args, convs->length_mod);
	if (convs->precision == 0 && nb == 0)
		return (ft_zero_zero(convs));
	sign = ft_get_sign(convs, nb);
	zeros = ft_count_zeros_di(convs, nb, sign);
	blanks = ft_count_blanks_di(convs, zeros, nb, sign);
	if (!ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	if (sign)
		ft_putchar(sign);
	ft_put_zeros(zeros);
	if (nb < 0)
		ft_put_unsigned_base((unsigned long long)(nb * -1), 10, 0);
	else
		ft_putnbr_ll(nb);
	if (ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	if (sign && nb >= 0)
		return (zeros + blanks + 1 + ft_ll_len(nb));
	return (zeros + blanks + ft_ll_len(nb));
}
