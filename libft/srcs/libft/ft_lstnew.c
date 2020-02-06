/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:25:33 by llahti            #+#    #+#             */
/*   Updated: 2019/10/25 09:59:46 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*link;
	void			*cpy;
	size_t			size;

	link = (t_list*)malloc(sizeof(t_list));
	if (!content || content_size == 0)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		size = content_size;
		cpy = (void*)malloc(size);
		if (!cpy)
			return (NULL);
		ft_memcpy(cpy, content, size);
		link->content = cpy;
		link->content_size = size;
	}
	link->next = NULL;
	return (link);
}
