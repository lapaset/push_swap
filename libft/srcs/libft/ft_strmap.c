/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:10:26 by llahti            #+#    #+#             */
/*   Updated: 2019/10/21 16:12:20 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		i;

	result = (char*)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = f(s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
