/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 13:35:19 by llahti            #+#    #+#             */
/*   Updated: 2020/01/09 13:32:59 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_unsigned_len(unsigned long long nb, int base)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}
