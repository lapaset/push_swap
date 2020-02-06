/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:23:26 by llahti            #+#    #+#             */
/*   Updated: 2019/10/23 09:39:25 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	result = (char*)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = f(i, (char)s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
