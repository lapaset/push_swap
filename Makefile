# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:50:29 by llahti            #+#    #+#              #
#    Updated: 2020/02/06 15:18:00 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
ODIR = objs
SDIR = srcs
INC = includes/
LIB = libft/libft.a
LIBDIR = libft
_OBJS = checker.o make_list.o utilities.o
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))
GREEN = \033[1;32m
EOC = \033[1;0m

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	@[ -d $(ODIR) ] || mkdir $(ODIR)
	@gcc -Wall -Wextra -Werror -c -I $(INC) -o $@ $<

$(NAME): $(OBJS)
	@make -C $(LIBDIR)
	@gcc -o $(NAME) $(OBJS) $(LIB) -I $(INC)
	@echo "$(RED)Checker created$(EOC)"

clean:
	@rm -Rf -r $(ODIR)
	@echo "Checker objects removed"
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -Rf -r $(NAME)
	@echo "Checker removed"
	@make -C $(LIBDIR) libclean

re: fclean all

.PHONY: all clean fclean re