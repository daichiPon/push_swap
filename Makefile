CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

SRCS = srcs/main.c srcs/utils/check.c srcs/utils/compute_disorder.c srcs/utils/init_stack.c srcs/utils/bench.c srcs/utils/bench_utils.c srcs/utils/op_output.c\
	srcs/libft/ft_atoi.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstnew.c srcs/libft/ft_strcmp.c srcs/libft/ft_strncmp.c\
	srcs/algorithms/medium.c srcs/algorithms/complex.c srcs/algorithms/sort_simple.c srcs/algorithms/sort_utils.c srcs/algorithms/adaptive.c\
	srcs/operations/push_handler.c srcs/operations/reverse_rotate_handler.c srcs/operations/rotate_handler.c srcs/operations/swap_handler.c\

OBJS = $(SRCS:.c=.o)

NAME = push_swap

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
