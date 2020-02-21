# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:50:29 by llahti            #+#    #+#              #
#    Updated: 2020/02/21 16:18:08 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap
ODIR = objs
SDIR = srcs
INC = includes/
LIB = libft/libft.a
LIBDIR = libft
_OBJS_CHECKER = checker.o make_list.o utilities.o operations.o instructions.o\
	visualize.o draw_stack.o
_OBJS_PUSH_SWAP = push_swap.o make_list.o utilities.o quicksort.o operations.o\
	ps_operations.o combine_sort.o sort_utilities.o sort_utilities2.o\
	cs_sort_a.o cs_utilities.o cs_split.o pivot.o
OBJS_CHECKER = $(patsubst %, $(ODIR)/%, $(_OBJS_CHECKER))
OBJS_PUSH_SWAP = $(patsubst %, $(ODIR)/%, $(_OBJS_PUSH_SWAP))
GREEN = \033[1;32m
EOC = \033[1;0m

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(ODIR)/%.o: $(SDIR)/%.c
	@[ -d $(ODIR) ] || mkdir $(ODIR)
	@gcc -Wall -Wextra -Werror -c -I $(INC) -o $@ $<

$(NAME_CHECKER): $(OBJS_CHECKER)
	@make -C $(LIBDIR)
	@gcc -o $(NAME_CHECKER) $(OBJS_CHECKER) $(LIB) -I $(INC)\
		-I /usr/local/include -I /usr/local/lib/ -lmlx\
		-framework OpenGL -framework AppKit
	@echo "$(GREEN)Checker created$(EOC)"

$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP)
	@make -C $(LIBDIR)
	@gcc -o $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) $(LIB) -I $(INC)
	@echo "$(GREEN)Push_swap created$(EOC)"

clean:
	@rm -Rf -r $(ODIR)
	@echo "Checker objects removed"
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -Rf -r $(NAME_CHECKER) $(NAME_PUSH_SWAP)
	@echo "Checker removed"
	@make -C $(LIBDIR) libclean

re: fclean all

.PHONY: all clean fclean re