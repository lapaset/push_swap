/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:52:18 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:08:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_specifier(const char *form, int i)
{
	while (ft_is_flag(form[i]))
		i++;
	if (form[i] == '*')
		i++;
	while (ft_isdigit(form[i]))
		i++;
	if (form[i] == '.')
	{
		i++;
		if (form[i] == '*')
			i++;
		if (form[i] == '-')
			i++;
		while (ft_isdigit(form[i]))
			i++;
	}
	if (form[i] == 'h' || form[i] == 'l' || form[i] == 'L')
		i++;
	if (form[i] == 'h' || form[i] == 'l')
		i++;
	if (ft_is_conv(form[i]))
		return (form[i]);
	return ('\0');
}

static int	ft_add_min_width(t_convs **elem, const char *form, int i)
{
	while (form[i] == '*')
	{
		i++;
		(*elem)->min_width = -2;
		return (i);
	}
	if (!ft_isdigit(form[i]))
	{
		(*elem)->min_width = -1;
		return (i);
	}
	(*elem)->min_width = ft_atoi(&form[i]);
	return (i + ft_intlen((*elem)->min_width));
}

static int	ft_add_precision(t_convs **elem, const char *form, int i)
{
	if (form[i] != '.')
	{
		if ((*elem)->specifier == 'f')
			(*elem)->precision = 6;
		else
			(*elem)->precision = -1;
		return (i);
	}
	i++;
	while (form[i] == '*')
	{
		i++;
		(*elem)->precision = -2;
		return (i);
	}
	if (!ft_isdigit(form[i]))
	{
		(*elem)->precision = 0;
		return (i);
	}
	(*elem)->precision = ft_atoi(&form[i]);
	return (i + ft_intlen((*elem)->precision));
}

void		ft_create_conv(t_convs **elem, const char *form, int i)
{
	if (!(*elem = (t_convs*)malloc(sizeof(t_convs))))
		exit(1);
	if (((*elem)->specifier = ft_get_specifier(form, i)) == '\0')
	{
		free(*elem);
		*elem = NULL;
		return ;
	}
	(*elem)->first_of_form = form[i];
	i = ft_add_flags(elem, form, i);
	i = ft_add_min_width(elem, form, i);
	i = ft_add_precision(elem, form, i);
	ft_add_length_mod(elem, &form[i]);
	(*elem)->next = NULL;
}
