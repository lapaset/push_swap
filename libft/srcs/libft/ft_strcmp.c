/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 09:33:24 by llahti            #+#    #+#             */
/*   Updated: 2019/11/04 12:35:09 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *c1;
	unsigned char *c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (*c1 != 0 && *c1 == *c2)
	{
		c1++;
		c2++;
	}
	return (*c1 - *c2);
}
