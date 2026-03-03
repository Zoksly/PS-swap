NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
DPRINTF_DIR = ../ft_dprintf

SRCS = main.c \
	push_swap.c \
	utils.c \
	../Operations/op1.c \
	../Operations/op2.c \
	../Operations/op3.c \
	../Operations/op4.c \
	../Algos/simple.c \
	../Algos/medium.c \
	../Algos/complex.c \
	../Algos/helpers.c \
	../Algos/hardcodes.c \
	$(DPRINTF_DIR)/ft_dprintf.c \
	$(DPRINTF_DIR)/ft_putchar.c \
	$(DPRINTF_DIR)/ft_putstr.c \
	$(DPRINTF_DIR)/ft_putnbr.c \
	$(DPRINTF_DIR)/ft_putunbr.c \
	$(DPRINTF_DIR)/ft_putadress.c \
	$(DPRINTF_DIR)/ft_puthexa_lower.c \
	$(DPRINTF_DIR)/ft_puthexa_upper.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I../Push_swap -I$(LIBFT_DIR) -I$(DPRINTF_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re