/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:44:42 by llahti            #+#    #+#             */
/*   Updated: 2020/01/14 14:18:23 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_colors[16] = {"{black}", "{red}", "{green}", "{yellow}", "{blue}",
	"{magenta}", "{cyan}", "{white}", "{bright black}", "{bright red}",
	"{bright green}", "{bright yellow}", "{bright blue}", "{bright magenta}",
	"{bright cyan}", "{bright white}"};

char	*g_fg_color_codes[16] = {"30", "31", "32", "33", "34", "35", "36", "37",
	"90", "91", "92", "93", "94", "95", "96", "97"};

char	*g_bg_color_codes[16] = {"40", "41", "42", "43", "44", "45", "46", "47",
	"100", "101", "102", "103", "104", "105", "106", "107"};

char	*g_ansi[4] = {"{eoc}", "{bold}", "{faint}", "{italic}"};

static int	ft_change_color(const char *str, int fg)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		if (ft_strnequ(g_colors[i], str, ft_strlen(g_colors[i])))
		{
			write(1, "\033[", 2);
			if (fg)
				write(1, g_fg_color_codes[i], ft_strlen(g_fg_color_codes[i]));
			else
				write(1, g_bg_color_codes[i], ft_strlen(g_bg_color_codes[i]));
			write(1, "m", 1);
			return (ft_strlen(g_colors[i]));
		}
		i++;
	}
	return (0);
}

int			ft_check_color(const char *str)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		if (ft_strnequ(g_ansi[i], str, ft_strlen(g_ansi[i])))
		{
			c = i + '0';
			write(1, "\033[", 2);
			write(1, &c, 1);
			write(1, "m", 1);
			return (ft_strlen(g_ansi[i]));
		}
		i++;
	}
	if (ft_strnequ("{bg}", str, 4))
		return (4 + ft_change_color(&str[4], 0));
	return (ft_change_color(str, 1));
}
