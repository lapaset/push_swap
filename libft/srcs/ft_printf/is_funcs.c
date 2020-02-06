/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:51:02 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 12:15:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f' ||
			c == '%' || c == 'b');
}

int		ft_is_flag(char c)
{
	return (c == '#' || c == '0' || c == '+' || c == '-' || c == ' ');
}

int		ft_is_form(char c)
{
	return (ft_is_flag(c) || ft_isdigit(c) || ft_is_conv(c) ||
			c == '.' || c == 'h' || c == 'l' || c == 'L' || c == '*');
}

int		ft_is_left_oriented(t_convs *convs)
{
	return (ft_has_flag(convs, '-'));
}
