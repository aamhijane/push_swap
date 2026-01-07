
NAME=push_swap

CC=cc
CFLAGS=#-Wall -Wextra -Werror 

SOURCE_FILES=push_swap.c utils.c operations.c validation.c parsing.c
OBJECT_FILES=$(SOURCE_FILES:.c=.o)

LIBFT_PATH=libft/
FT_PRINTF_PATH=ft_printf/

LIBFT_LIB=$(LIBFT_PATH)libft.a
FT_PRINTF_LIB=$(FT_PRINTF_PATH)libftprintf.a

INCLUDES=-I./$(LIBFT_PATH) -I./$(FT_PRINTF_PATH)

all: $(NAME)

$(NAME): $(OBJECT_FILES) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJECT_FILES) $(LIBFT_LIB) $(FT_PRINTF_LIB) -o $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_PATH)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)

re: fclean all

.PHONY: all clean fclean re
