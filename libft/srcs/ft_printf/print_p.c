/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 10:15:49 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 13:08:56 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putpointer(void *data, int precision)
{
	size_t	nb;
	int		i;

	if (data == NULL)
	{
		if (precision == 0)
			write(1, "0x", 2);
		else
			write(1, "0x0", 3);
		return ;
	}
	nb = (size_t)data;
	i = 2;
	write(1, "0x", 2);
	ft_put_unsigned_base(nb, 16, 0);
}

static int	ft_pointerlen(void *ptr)
{
	int		len;
	size_t	nb;

	nb = (size_t)ptr;
	if (nb == 0)
		return (3);
	len = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len + 2);
}

int			ft_print_p(t_convs *convs, va_list args)
{
	int		blanks;
	int		chars;
	void	*ptr;

	ptr = va_arg(args, void*);
	chars = ft_pointerlen(ptr);
	blanks = ft_count_blanks_csp(convs, chars);
	if (ft_is_left_oriented(convs))
		ft_putpointer(ptr, convs->precision);
	ft_put_chars(blanks, ' ');
	if (!ft_has_flag(convs, '-'))
		ft_putpointer(ptr, convs->precision);
	if (convs->min_width < chars)
		return (chars);
	return (convs->min_width);
}
