/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:36:40 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:11:17 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(va_list args, t_convs *convs, const char *form)
{
	int			i;
	int			chars;
	int			wrote;

	i = 0;
	chars = 0;
	while (convs)
	{
		wrote = ft_print_text(form, i, i, convs);
		chars += wrote;
		i += wrote + 1;
		while (form[i] != convs->specifier)
			i++;
		i++;
		if ((wrote = ft_print_data(convs, args)) < 0)
			return (wrote);
		chars += wrote;
		convs = convs->next;
	}
	return (chars + ft_print_rest(form, i));
}

static void	ft_free(t_convs *convs)
{
	t_convs		*temp;

	while (convs)
	{
		temp = convs->next;
		free(convs);
		convs = temp;
	}
}

int			ft_printf(const char *form, ...)
{
	va_list		args;
	t_convs		*convs;
	int			chars;

	convs = NULL;
	ft_list_convs(form, &convs);
	va_start(args, form);
	chars = ft_print(args, convs, form);
	va_end(args);
	ft_free(convs);
	return (chars);
}
