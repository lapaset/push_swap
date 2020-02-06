/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:58:51 by llahti            #+#    #+#             */
/*   Updated: 2019/10/25 14:37:54 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parts(char *s, char c)
{
	int		parts;

	while (*s != 0 && *s == c)
		s++;
	if (*s == 0)
		return (0);
	parts = 1;
	while (*s != 0)
	{
		if (*s == c && s[1] != c && s[1] != 0)
			parts++;
		s++;
	}
	return (parts);
}

static int	ft_len(char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*ft_next(char *s, int len)
{
	char	*result;
	int		i;

	result = (char*)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		parts;
	int		len;
	int		i;

	parts = ft_parts((char*)s, c);
	arr = (char**)malloc(sizeof(char*) * parts + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < parts)
	{
		while (*s == c)
			s++;
		len = ft_len((char*)s, c);
		arr[i] = ft_next((char*)s, len);
		s += len;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
