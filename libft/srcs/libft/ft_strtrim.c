/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:31:53 by llahti            #+#    #+#             */
/*   Updated: 2019/10/23 11:32:59 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimlen(char *s)
{
	int		ws;
	int		i;

	ws = 0;
	i = 0;
	while (s[i] == ' ' | s[i] == '\t' | s[i] == '\n')
	{
		ws++;
		i++;
	}
	if (s[i] == 0)
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' | s[i] == '\t' | s[i] == '\n')
	{
		ws++;
		i--;
	}
	return (ft_strlen(s) - ws);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		len;

	len = ft_trimlen((char*)s);
	trim = (char*)malloc(len + 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (s[i] == ' ' | s[i] == '\t' | s[i] == '\n')
		i++;
	j = 0;
	while (j < len)
	{
		trim[j] = s[i];
		i++;
		j++;
	}
	trim[j] = 0;
	return (trim);
}
