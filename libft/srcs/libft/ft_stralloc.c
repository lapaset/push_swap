/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:46:43 by llahti            #+#    #+#             */
/*   Updated: 2020/02/07 15:46:55 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stralloc(char *str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * ft_strlen(str));
	return (ft_strcpy(ret, str));
}
