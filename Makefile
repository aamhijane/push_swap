
NAME=push_swap

CC=cc
CFLAGS=-fsanitize=address -g -Wall -Wextra -Werror 

SOURCE_FILES=push_swap.c operations.c allocation.c stack_operations.c parsing.c validation.c utils.c
OBJECT_FILES=$(SOURCE_FILES:.c=.o)

LIBFT_PATH=libft/
LIBFT_LIB=$(LIBFT_PATH)libft.a

INCLUDES=-I./$(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
