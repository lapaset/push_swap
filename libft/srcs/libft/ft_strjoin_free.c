/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:10:57 by llahti            #+#    #+#             */
/*   Updated: 2019/11/06 10:16:36 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
	free(s1);
	free(s2);
	return (result);
}
