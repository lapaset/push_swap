/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:48:25 by llahti            #+#    #+#             */
/*   Updated: 2020/02/06 16:33:48 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/libft/libft.h"
# include <fcntl.h>

typedef struct 		s_lst
{
	int				nb;
	struct s_lst 	*next;
}					t_lst;

//utilities:
void				ft_print_lst(t_lst *lst);

//make_list:
t_lst				*ft_params_to_list(int arg, char **argv);

#endif