/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:18:21 by llahti            #+#    #+#             */
/*   Updated: 2019/10/21 10:26:02 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char *result;

	result = (char*)haystack;
	if (ft_strcmp(needle, "") == 0)
		return (result);
	while (*result != 0)
	{
		if (ft_strncmp(result, needle, ft_strlen(needle)) == 0)
			return (result);
		else
			result++;
	}
	return (NULL);
}
