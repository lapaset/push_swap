/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:53:53 by llahti            #+#    #+#             */
/*   Updated: 2020/02/17 13:40:10 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/srcs/libft/libft.h"
# include "stacks.h"

//quicksort:
void		ft_quicksort(t_stacks *stacks, int amount);

//ps_operations:
void		ft_psswap(t_stacks *stacks, char c);
void		ft_pspush(t_stacks *stacks, char c);
void		ft_psrotate(t_stacks *stacks, char c);
void		ft_psreverse_rotate(t_stacks *stacks, char c);
