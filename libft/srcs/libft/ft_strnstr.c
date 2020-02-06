/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 10:43:09 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 11:33:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char *result;

	result = (char*)haystack;
	if (ft_strcmp(needle, "") == 0)
		return (result);
	if (len == 0)
		return (NULL);
	while (*result != 0 && len - ft_strlen(needle) + 1 > 0)
	{
		if (ft_strncmp(result, needle, ft_strlen(needle)) == 0)
			return (result);
		else
		{
			result++;
			len--;
		}
	}
	return (NULL);
}
