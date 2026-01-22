# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/23 00:22:21 by ayamhija          #+#    #+#              #
#    Updated: 2026/01/23 00:22:35 by ayamhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= push_swap.c \
			  error.c \
			  libft_utils.c \
			  libft_utils2.c \
			  stack_utils.c \
			  stack_utils2.c \
			  op_swap.c \
			  op_push.c \
			  op_rotate.c \
			  op_reverse.c \
			  parsing.c \
			  validation.c \
			  index.c \
			  sort_three.c \
			  turk_sort.c \
			  cost_calc.c \
			  cost_calc2.c \
			  execute_move.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
