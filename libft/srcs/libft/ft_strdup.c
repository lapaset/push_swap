/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:18:32 by llahti            #+#    #+#             */
/*   Updated: 2019/10/21 16:11:46 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	dup = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
