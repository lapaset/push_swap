/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:06:48 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 13:07:27 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_asterisk_min_width(t_convs *convs, int min_width)
{
	size_t	i;

	if (min_width < 0)
	{
		if (!ft_has_flag(convs, '-') && !ft_replace_flag(convs->flags, '-'))
		{
			i = ft_strlen(convs->flags);
			convs->flags[i] = '-';
			convs->flags[i + 1] = '\0';
		}
		convs->min_width = min_width * -1;
		return ;
	}
	convs->min_width = min_width;
}

void		ft_add_asterisk_precision(t_convs *convs, int precision)
{
	if (precision < 0)
		convs->precision = -1;
	else
		convs->precision = precision;
}
