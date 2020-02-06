/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:24:31 by llahti            #+#    #+#             */
/*   Updated: 2020/01/10 12:27:41 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count_blanks_csp(t_convs *convs, int chars)
{
	if (convs->min_width - chars < 0)
		return (0);
	return (convs->min_width - chars);
}

int			ft_print_c(t_convs *convs, va_list args)
{
	char	c;
	int		blanks;

	c = va_arg(args, int);
	blanks = ft_count_blanks_csp(convs, 1);
	if (ft_is_left_oriented(convs))
		ft_putchar(c);
	if (blanks)
		ft_put_chars(blanks, ' ');
	if (!ft_is_left_oriented(convs))
		ft_putchar(c);
	return (blanks + 1);
}

int			ft_print_s(t_convs *convs, va_list args)
{
	char	*str;
	int		blanks;
	int		chars;

	str = va_arg(args, char*);
	if (str == NULL)
		chars = 6;
	else
		chars = ft_strlen(str);
	if (convs->precision >= 0 && chars >= convs->precision)
		chars = convs->precision;
	blanks = ft_count_blanks_csp(convs, chars);
	if (!ft_is_left_oriented(convs))
		ft_put_chars(blanks, ' ');
	if (str == NULL)
		write(1, "(null)", chars);
	else
		write(1, str, chars);
	if (ft_is_left_oriented(convs))
		ft_put_chars(blanks, ' ');
	return (chars + blanks);
}
