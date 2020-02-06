/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 11:57:36 by llahti            #+#    #+#             */
/*   Updated: 2019/10/25 14:22:37 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*mapped;
	t_list	*temp;
	t_list	*tail;

	if (!lst)
		return (NULL);
	mapped = f(lst);
	tail = mapped;
	temp = (t_list*)malloc(sizeof(t_list));
	while ((lst = lst->next))
	{
		temp = f(lst);
		if (!temp)
			return (NULL);
		tail->next = temp;
		tail = tail->next;
	}
	return (mapped);
}
