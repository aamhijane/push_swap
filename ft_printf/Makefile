# -*- Makefile -*-

SRC = ft_printf.c ft_utils.c ft_putnbr.c 

OBJS = ${SRC:.c=.o}

NAME = libftprintf.a

RM = rm -f

CC = cc
FLAGS = -Wall -Wextra -Werror

AR_LIB = ar
AR_LIB_FLAGS = rcs

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(AR_LIB) $(AR_LIB_FLAGS) $(NAME) ${OBJS}

all: $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(RM) $(OBJS)
