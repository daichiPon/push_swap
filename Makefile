CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I includes -I srcs/ft_printf

SRCS = srcs/main.c srcs/utils/check.c srcs/utils/compute_disorder.c srcs/utils/init_stack.c srcs/utils/bench.c\
	srcs/libft/ft_atoi.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstnew.c srcs/libft/ft_strcmp.c srcs/libft/ft_strncmp.c\
	srcs/algorithms/medium.c\
	srcs/algorithms/complex.c\
	srcs/operations/pa.c srcs/operations/pb.c\
	srcs/operations/ra.c srcs/operations/rb.c srcs/operations/rra.c srcs/operations/rrb.c\
	srcs/operations/rr.c srcs/operations/rrr.c srcs/operations/rotate.c srcs/operations/reverse_rotate.c\
	srcs/operations/sa.c srcs/operations/sb.c srcs/operations/ss.c\
	srcs/ft_printf/ft_printf.c srcs/ft_printf/ft_printf_utils.c\
	srcs/ft_printf/utils/ft_putchar.c srcs/ft_printf/utils/ft_putnbr.c srcs/ft_printf/utils/ft_putstr.c\
	srcs/ft_printf/utils/ft_putnbr_u.c srcs/ft_printf/utils/ft_puthex_big.c\
	srcs/ft_printf/utils/ft_puthex_lit.c srcs/ft_printf/utils/ft_puthex_p.c\
	srcs/ft_printf/utils/ft_strchr.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

LIBFT_DIR = srcs/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME).a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME).a

re:
	$(MAKE) fclean
	$(MAKE) all


.PHONY: all clean fclean re
