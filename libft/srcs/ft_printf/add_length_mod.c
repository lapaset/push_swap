/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_length_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:02:29 by llahti            #+#    #+#             */
/*   Updated: 2020/01/10 12:03:44 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_length_mod(const char *form)
{
	if (ft_is_conv(*form))
		return (0);
	if (ft_is_conv(form[1]))
	{
		if (*form == 'h')
			return (2);
		if (*form == 'l')
			return (3);
		if (*form == 'L' && form[1] == 'f')
			return (5);
		return (-1);
	}
	if (ft_is_conv(form[2]))
	{
		if (form[1] == 'h')
			return (1);
		else if (form[1] == 'l')
			return (4);
	}
	return (-1);
}

int			ft_add_length_mod(t_convs **elem, const char *form)
{
	int			mod;

	mod = ft_get_length_mod(form);
	(*elem)->length_mod = mod;
	return (mod);
}
