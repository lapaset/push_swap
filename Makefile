# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:50:29 by llahti            #+#    #+#              #
#    Updated: 2020/02/11 17:20:06 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
ODIR = objs
SDIR = srcs
INC = includes/
LIB = libft/libft.a
LIBDIR = libft
_OBJS_CHECKER = checker.o make_list.o utilities.o operations.o instructions.o\
	visualize.o draw_stack.o
OBJS_CHECKER = $(patsubst %, $(ODIR)/%, $(_OBJS_CHECKER))
GREEN = \033[1;32m
EOC = \033[1;0m

all: $(NAME_CHECKER)

$(ODIR)/%.o: $(SDIR)/%.c
	@[ -d $(ODIR) ] || mkdir $(ODIR)
	@gcc -Wall -Wextra -Werror -c -I $(INC) -o $@ $<

$(NAME_CHECKER): $(OBJS_CHECKER)
	@make -C $(LIBDIR)
	@gcc -o $(NAME_CHECKER) $(OBJS_CHECKER) $(LIB) -I $(INC)\
		-I /usr/local/include -I /usr/local/lib/ -lmlx\
		-framework OpenGL -framework AppKit
	@echo "$(RED)Checker created$(EOC)"

clean:
	@rm -Rf -r $(ODIR)
	@echo "Checker objects removed"
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -Rf -r $(NAME_CHECKER)
	@echo "Checker removed"
	@make -C $(LIBDIR) libclean

re: fclean all

.PHONY: all clean fclean re