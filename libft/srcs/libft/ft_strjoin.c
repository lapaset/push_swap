/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:20:39 by llahti            #+#    #+#             */
/*   Updated: 2019/10/21 16:13:58 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	result = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}
