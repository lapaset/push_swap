/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:00:25 by llahti            #+#    #+#             */
/*   Updated: 2020/01/08 14:00:42 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_chars(int amount, char c)
{
	char	chars[amount];
	int		i;

	if (amount < 1)
		return ;
	i = 0;
	while (i < amount)
	{
		chars[i] = c;
		i++;
	}
	write(1, chars, amount);
}
