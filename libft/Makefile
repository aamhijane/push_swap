# -*- Makefile -*-

SRC = ft_tolower.c ft_strdup.c ft_putnbr_fd.c ft_isprint.c ft_memchr.c ft_strnstr.c ft_toupper.c ft_strtrim.c ft_memcpy.c ft_striteri.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_strchr.c ft_strjoin.c ft_memmove.c ft_putchar_fd.c ft_substr.c ft_strlcpy.c ft_itoa.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_memcmp.c ft_memset.c ft_strlen.c ft_strlcat.c ft_strncmp.c ft_split.c ft_putstr_fd.c ft_strrchr.c ft_putendl_fd.c ft_atoi.c ft_strmapi.c
B_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c ft_lstdelone_bonus.c

OBJS = ${SRC:.c=.o}
B_OBJS = ${B_SRC:.c=.o}

NAME = libft.a

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

bonus: $(B_OBJS)
	$(AR_LIB) $(AR_LIB_FLAGS) $(NAME) $(B_OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
