/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llahti <llahti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:37:57 by llahti            #+#    #+#             */
/*   Updated: 2020/01/28 11:54:50 by llahti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct		s_convs
{
	char			specifier;
	char			flags[6];
	int				min_width;
	int				precision;
	int				length_mod;
	char			first_of_form;
	struct s_convs	*next;
}					t_convs;

int					ft_printf(const char *form, ...);

int					ft_add_flags(t_convs **elem, const char *form, int i);
int					ft_replace_flag(char *flags, char flag);

int					ft_add_length_mod(t_convs **elem, const char *form);

void				ft_add_asterisk_precision(t_convs *convs, int precision);
void				ft_add_asterisk_min_width(t_convs *convs, int min_width);

void				ft_create_conv(t_convs **elem, const char *form, int i);

char				*ft_double_to_str(long double nb, t_convs *convs);

int					ft_is_conv(char c);
int					ft_is_flag(char c);
int					ft_is_form(char c);
int					ft_is_left_oriented(t_convs *convs);

void				ft_list_convs(const char *form, t_convs **convs);

int					ft_print_c(t_convs *convs, va_list args);
int					ft_print_s(t_convs *convs, va_list args);
int					ft_count_blanks_csp(t_convs *convs, int chars);

int					ft_print_di(t_convs *convs, va_list args);

int					ft_print_f(t_convs *convs, va_list args);

int					ft_print_p(t_convs *convs, va_list args);

int					ft_print_ouxxb(t_convs *convs, va_list args, int base,
					int is_upper);

int					ft_get_base(t_convs *convs);
int					ft_has_flag(t_convs *convs, char flag);
void				ft_put_blanks(int amount);
void				ft_put_zeros(int amount);
int					ft_zero_zero(t_convs *convs);

int					ft_print_text(const char *form, int i, int start,
					t_convs *convs);
int					ft_print_data(t_convs *convs, va_list args);
int					ft_print_rest(const char *form, int i);

int					ft_check_color(const char *str);

#endif
