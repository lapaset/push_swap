/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:51:33 by llahti            #+#    #+#             */
/*   Updated: 2019/10/29 18:31:01 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*rev;
	size_t	i;

	rev = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!rev)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		rev[i] = str[ft_strlen(str) - 1 - i];
		i++;
	}
	rev[i] = 0;
	return (rev);
}
