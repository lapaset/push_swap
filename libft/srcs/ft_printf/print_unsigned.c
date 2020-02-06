/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:06:58 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 13:05:23 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	ft_cast_to_ull(int length_mod, va_list args)
{
	unsigned char	uhh;
	unsigned short	uh;
	unsigned int	ui;
	unsigned long	ul;

	if (length_mod == 0)
		ui = va_arg(args, unsigned int);
	if (length_mod == 1)
		uhh = va_arg(args, unsigned int);
	if (length_mod == 2)
		uh = va_arg(args, unsigned int);
	if (length_mod == 3)
		ul = va_arg(args, unsigned long);
	if (length_mod == 4)
		return (va_arg(args, unsigned long long));
	if (length_mod == 0)
		return ((long long)ui);
	if (length_mod == 1)
		return ((long long)uhh);
	if (length_mod == 2)
		return ((long long)uh);
	if (length_mod == 3)
		return ((long long)ul);
	return (-1);
}

static int					ft_count_zeros_us(t_convs *convs,
							unsigned long long nb,
							int base)
{
	int					zeros;

	zeros = 0;
	if (convs->precision != -1)
		zeros = convs->precision - ft_unsigned_len(nb, base);
	else if (ft_has_flag(convs, '0'))
		zeros = convs->min_width - ft_unsigned_len(nb, base);
	else
		zeros = 0;
	if ((convs->specifier == 'x' || convs->specifier == 'X') &&
		ft_has_flag(convs, '#'))
		zeros -= 2;
	if (convs->specifier == 'o' && ft_has_flag(convs, '#') && nb != 0)
		zeros--;
	if (zeros < 0)
		return (0);
	return (zeros);
}

static int					ft_count_blanks_us(t_convs *convs,
							unsigned long long nb,
							int base, int zeros)
{
	int blanks;

	blanks = convs->min_width - ft_unsigned_len(nb, base) - zeros;
	if ((convs->specifier == 'x' || convs->specifier == 'X')
		&& ft_has_flag(convs, '#') && nb != 0)
		blanks -= 2;
	if (convs->specifier == 'o' && ft_has_flag(convs, '#') && nb != 0)
		blanks--;
	if (blanks < 0)
		return (0);
	return (blanks);
}

static int					ft_count_ret_val(unsigned long long nb,
							int blanks, int zeros, t_convs *convs)
{
	if ((convs->specifier == 'x' || convs->specifier == 'X')
		&& ft_has_flag(convs, '#') && nb != 0)
		return (ft_unsigned_len(nb, ft_get_base(convs)) + blanks + zeros + 2);
	if (convs->specifier == 'o' && ft_has_flag(convs, '#') && nb != 0)
		return (ft_unsigned_len(nb, ft_get_base(convs)) + blanks + zeros + 1);
	return (ft_unsigned_len(nb, ft_get_base(convs)) + blanks + zeros);
}

int							ft_print_ouxxb(t_convs *convs, va_list args,
							int base, int is_upper)
{
	unsigned long long	nb;
	int					zeros;
	int					blanks;

	nb = ft_cast_to_ull(convs->length_mod, args);
	if (convs->precision == 0 && nb == 0)
		return (ft_zero_zero(convs));
	zeros = ft_count_zeros_us(convs, nb, base);
	blanks = ft_count_blanks_us(convs, nb, base, zeros);
	if (!ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	if (convs->specifier == 'x' && ft_has_flag(convs, '#') && nb != 0)
		ft_putstr("0x");
	if (convs->specifier == 'X' && ft_has_flag(convs, '#') && nb != 0)
		ft_putstr("0X");
	if (convs->specifier == 'o' && ft_has_flag(convs, '#') && nb != 0)
		ft_putstr("0");
	ft_put_zeros(zeros);
	ft_put_unsigned_base(nb, base, is_upper);
	if (ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	return (ft_count_ret_val(nb, blanks, zeros, convs));
}
