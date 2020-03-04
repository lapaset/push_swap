# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llahti <llahti@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 13:50:29 by llahti            #+#    #+#              #
#    Updated: 2020/03/03 20:12:33 by llahti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER = checker
NAME_PUSH_SWAP = push_swap
ODIR = objs
SDIR = srcs
INC = includes/
LIB = libft/libft.a
LIBDIR = libft
_OBJS_STACKS = stacks_make_list.o stacks_utilities.o stacks_operations.o\
	stacks_elem_functions.o
_OBJS_CHECKER = $(_OBJS_STACKS) checker.o checker_deal_instructions.o\
	checker_read_instructions.o checker_visualize.o checker_draw_stack.o\
	checker_visualize_moves.o checker_key_events.o checker_utilities.o
_OBJS_PUSH_SWAP = $(_OBJS_STACKS) push_swap.o small_sort.o\
	push_swap_operations.o combine_sort.o push_swap_utilities.o\
	push_swap_rotate_to.o combine_sort_sort_a.o combine_sort_split.o\
	combine_sort_pivot.o push_swap_sort_utilities.o combine_sort_part_to_a.o\
	push_swap_smallest_biggest.o quicksort.o push_swap_sort_three.o
OBJS_CHECKER = $(patsubst %, $(ODIR)/%, $(_OBJS_CHECKER))
OBJS_PUSH_SWAP = $(patsubst %, $(ODIR)/%, $(_OBJS_PUSH_SWAP))
GREEN = \033[1;32m
EOC = \033[1;0m

all: $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(ODIR)/%.o: $(SDIR)/%.c $(INC)*
	@[ -d $(ODIR) ] || mkdir $(ODIR)
	@gcc -Wall -Wextra -Werror -c -I $(INC) -o $@ $<

$(NAME_CHECKER): $(OBJS_CHECKER)
	@make -C $(LIBDIR)
	@gcc -o $(NAME_CHECKER) $(OBJS_CHECKER) $(LIB)\
		-I /usr/local/include -I /usr/local/lib/ -lmlx\
		-framework OpenGL -framework AppKit
	@echo "$(GREEN)Checker created$(EOC)"

$(NAME_PUSH_SWAP): $(OBJS_PUSH_SWAP)
	@make -C $(LIBDIR)
	@gcc -o $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) $(LIB)
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