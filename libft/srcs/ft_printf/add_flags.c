/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 14:54:51 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:06:44 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	g_flags[11][6] = {"c-", "s-", "p-", "d +-0", "i +-0", "o-0#", "u-0#",
	"x-0#", "X-0#", "f +-0#", "% +-0#"};

static int	ft_ignore_flag(t_convs *elem, char flag)
{
	char		*temp;

	if (flag == '#' || flag == '+' || flag == '-')
		return (0);
	temp = elem->flags;
	while (*temp != '\0')
	{
		if ((flag == '0' && *temp == '-') || (flag == ' ' && *temp == '+'))
			return (1);
		temp++;
	}
	return (0);
}

static int	ft_check_flag(char flag, char type, t_convs *elem)
{
	int			i;
	int			j;

	i = 0;
	while (g_flags[i][0] != type)
		i++;
	j = 1;
	while (g_flags[i][j] != '\0')
	{
		if (g_flags[i][j] == flag)
		{
			if (ft_has_flag(elem, flag) || ft_ignore_flag(elem, flag))
				return (0);
			return (1);
		}
		j++;
	}
	return (0);
}

int			ft_replace_flag(char *flags, char flag)
{
	char		*temp;

	if (flag == '#' || flag == ' ' || flag == '0')
		return (0);
	temp = flags;
	while (*temp != '\0')
	{
		if (flag == '+' && *temp == ' ')
		{
			*temp = '+';
			return (1);
		}
		if (flag == '-' && *temp == '0')
		{
			*temp = '-';
			return (1);
		}
		temp++;
	}
	return (0);
}

int			ft_add_flags(t_convs **elem, const char *form, int i)
{
	int			j;

	ft_bzero((*elem)->flags, 6);
	j = 0;
	while (ft_is_flag(form[i]))
	{
		if (ft_check_flag(form[i], (*elem)->specifier, *elem)
		&& !ft_replace_flag((*elem)->flags, form[i]))
		{
			(*elem)->flags[j] = form[i];
			j++;
		}
		i++;
	}
	(*elem)->flags[j] = '\0';
	return (i);
}
