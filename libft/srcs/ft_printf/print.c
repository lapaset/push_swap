/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:42:14 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:17:57 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_func_arr[6])(t_convs*, va_list) = {&ft_print_c, &ft_print_s,
	&ft_print_p, &ft_print_di, &ft_print_di, &ft_print_f};

char	*g_specifier_arr = "cspdifouxXb";

static int	ft_print_precent(t_convs *convs)
{
	if (ft_has_flag(convs, '-'))
		ft_putchar('%');
	ft_put_chars(convs->min_width - 1, ' ');
	if (!ft_has_flag(convs, '-'))
		ft_putchar('%');
	if (convs->min_width < 1)
		return (1);
	return (convs->min_width);
}

int			ft_print_data(t_convs *convs, va_list args)
{
	int		i;
	int		is_upper;

	if (convs->min_width == -2)
		ft_add_asterisk_min_width(convs, va_arg(args, int));
	if (convs->precision == -2)
		ft_add_asterisk_precision(convs, va_arg(args, int));
	if (convs->specifier == '%')
		return (ft_print_precent(convs));
	i = 0;
	while (g_specifier_arr[i] != convs->specifier)
		i++;
	if (i < 6)
		return (g_func_arr[i](convs, args));
	if (convs->specifier == 'X')
		is_upper = 1;
	else
		is_upper = 0;
	return (ft_print_ouxxb(convs, args, ft_get_base(convs), is_upper));
}

static int	ft_put_text(const char *form, int i, int start)
{
	if (i - start == 0)
		return (0);
	write(1, &form[start], i - start);
	return (i - start);
}

int			ft_print_rest(const char *form, int i)
{
	int		start;
	int		chars;

	chars = 0;
	start = i;
	while (form[i] != '\0')
	{
		if (form[i] == '{')
		{
			chars += ft_put_text(form, i, start);
			i += ft_check_color(&form[i]);
			start = i;
		}
		else if (form[i] == '%')
		{
			chars += ft_put_text(form, i, start);
			i++;
			return (chars + ft_print_rest(form, i));
		}
		else
			i++;
	}
	chars += ft_put_text(form, i, start);
	return (chars);
}

int			ft_print_text(const char *form, int i, int start, t_convs *convs)
{
	int		ret;
	int		chars;

	chars = 0;
	while (!(form[i] == '%' && form[i + 1] == convs->first_of_form))
	{
		if (form[i] == '{')
		{
			chars += ft_put_text(form, i, start);
			ret = ft_check_color(&form[i]);
			i += ret;
			start = i;
			if (ret != 0)
				i--;
		}
		else if (form[i] == '%')
		{
			chars += ft_put_text(form, i, start);
			i++;
			return (chars + ft_print_text(&form[i], i, start, convs));
		}
		i++;
	}
	chars += ft_put_text(form, i, start);
	return (chars);
}
