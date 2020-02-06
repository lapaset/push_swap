/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:40:36 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:18:45 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_get_double(t_convs *convs, va_list args)
{
	double		d;

	if (convs->length_mod == 5)
		return (va_arg(args, long double));
	d = va_arg(args, double);
	return ((long double)d);
}

static int			ft_handle_signs(t_convs *convs, long double nb)
{
	if (nb < 0)
		ft_putchar('-');
	else if (ft_has_flag(convs, '+'))
		ft_putchar('+');
	else if (ft_has_flag(convs, ' '))
		ft_putchar(' ');
	else
		return (0);
	return (1);
}

static int			ft_double_len(t_convs *convs, long double nb)
{
	int			chars;

	chars = ft_ll_len((long long)nb);
	if ((ft_has_flag(convs, '+') || ft_has_flag(convs, ' ')) &&
		nb >= 0)
		chars++;
	if (convs->precision != 0 || ft_has_flag(convs, '#'))
		chars++;
	if (convs->precision > 0)
		chars += convs->precision;
	return (chars);
}

static int			ft_count_zeros_f(t_convs *convs, long double nb)
{
	int			zeros;

	zeros = 0;
	if (ft_has_flag(convs, '0'))
		zeros = convs->min_width - ft_double_len(convs, nb);
	if (zeros < 0)
		return (0);
	return (zeros);
}

int					ft_print_f(t_convs *convs, va_list args)
{
	long double	nb;
	int			zeros;
	int			blanks;
	char		*str;
	int			sign;

	nb = ft_get_double(convs, args);
	str = ft_double_to_str(nb, convs);
	zeros = ft_count_zeros_f(convs, nb);
	blanks = convs->min_width - ft_double_len(convs, nb) - zeros;
	if (blanks < 0)
		blanks = 0;
	if (!ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	sign = ft_handle_signs(convs, nb);
	ft_put_zeros(zeros);
	ft_putstr(str);
	if (ft_is_left_oriented(convs))
		ft_put_blanks(blanks);
	return (zeros + blanks + sign + ft_strlen(str));
}
