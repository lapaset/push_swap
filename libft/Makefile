# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 16:29:38 by llahti            #+#    #+#              #
#    Updated: 2020/02/07 17:18:51 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
ODIR = objs
SDIR = srcs
_LIBFT = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o\
ft_memchr.o ft_memcmp.o ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o\
ft_strcat.o ft_strncat.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o\
ft_strcmp.o ft_strncmp.o ft_atoi.o ft_isalpha.o ft_isdigit.o ft_isalnum.o\
ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o ft_isspace.o ft_islower.o\
ft_isupper.o ft_memalloc.o ft_memdel.o ft_put_chars.o ft_strnew.o ft_strdel.o\
ft_strclr.o ft_striter.o ft_unsigned_len.o ft_put_unsigned_base.o ft_striteri.o\
ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o\
ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putchar.o ft_putstr.o ft_putendl.o\
ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
ft_lstnew.o ft_lstdelone.o ft_lstadd.o ft_lstiter.o ft_lstmap.o ft_lstdel.o\
ft_intlen.o ft_strrev.o ft_strjoin_free.o ft_strsub_free.o ft_sqrt.o\
ft_strnew_chr.o ft_strccpy.o ft_itoa_base.o ft_ll_len.o ft_putnbr_ll.o\
ft_swap_ptrs.o ft_hexa_to_int.o ft_is_hexa.o ft_hexa_len.o ft_power.o\
ft_stralloc.o ft_strnstr.o
_GNL = get_next_line.o
_PRINTF = ft_printf.o list_convs.o print.o is_funcs.o create_conv.o add_flags.o\
print_cs.o print_di.o print_p.o print_unsigned.o print_f.o double_to_str.o\
style.o asterisk.o add_length_mod.o print_utilities.o
LIBFT = $(patsubst %, libft/%, $(_LIBFT))
GNL = $(patsubst %, gnl/%, $(_GNL))
PRINTF = $(patsubst %, ft_printf/%, $(_PRINTF))
_OBJS = $(LIBFT) $(GNL) $(PRINTF)
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	@[ -d $(ODIR) ] || mkdir -p $(ODIR)
	@[ -d $(ODIR)/libft ] || mkdir -p $(ODIR)/libft
	@[ -d $(ODIR)/gnl ] || mkdir -p $(ODIR)/gnl
	@[ -d $(ODIR)/ft_printf ] || mkdir -p $(ODIR)/ft_printf
	@gcc -Wall -Wextra -Werror -c -o $@ $<

$(NAME): $(OBJS)
	@echo "\033[1;32mLibrary objects created\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[1;32mLibrary created\033[0m"

clean:
	@rm -f -r $(ODIR)
	@echo "\033[1;32mLibrary objects removed\033[0m"

libclean:
	@rm -f $(NAME)
	@echo "\033[1;32mLibrary removed\033[0m"

fclean: clean libclean

re: fclean all

.PHONY: all clean fclean re
