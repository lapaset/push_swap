/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_convs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:55:57 by llahti            #+#    #+#             */
/*   Updated: 2020/01/13 11:17:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_elem(t_convs **convs, const char *form, int i)
{
	t_convs		*temp;

	temp = *convs;
	while (temp->next)
		temp = temp->next;
	ft_create_conv(&(temp->next), form, i);
}

void		ft_list_convs(const char *form, t_convs **convs)
{
	int			i;

	i = 0;
	while (form[i] != '\0')
	{
		i++;
		if (form[i - 1] == '%' && ft_is_form(form[i]))
		{
			if (*convs == NULL)
				ft_create_conv(convs, form, i);
			else
				ft_add_elem(convs, form, i);
			i++;
		}
	}
}
