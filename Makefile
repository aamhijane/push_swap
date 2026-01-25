# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayamhija <ayamhija@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 00:45:32 by ayamhija          #+#    #+#              #
#    Updated: 2026/01/26 00:46:00 by ayamhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
GNL_DIR = get_next_line

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRCS = push_swap.c \
       parse.c \
       parse_utils.c \
       parse_utils2.c \
       error.c \
       utils.c \
       swap.c \
       push.c \
       rotate.c \
       reverse_rotate.c \
       sort_small.c \
       sort_large.c \
       sort_large2.c

# Bonus uses same files except main
BONUS_SRCS = checker_bonus.c \
             parse.c \
             parse_utils.c \
             parse_utils2.c \
             error.c \
             utils.c \
             utils_bonus.c \
             swap.c \
             push.c \
             rotate.c \
             reverse_rotate.c

GNL_SRCS = $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(FT_PRINTF) $(BONUS_OBJS) $(GNL_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(GNL_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
