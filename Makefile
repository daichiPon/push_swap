CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = srcs/main.c srcs/utils/check.c srcs/utils/compute_disorder.c srcs/utils/init_stack.c\
	srcs/libft/ft_atoi.c srcs/libft/ft_lstadd_back.c srcs/libft/ft_lstnew.c srcs/libft/ft_strcmp.c

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
