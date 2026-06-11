CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = utils/ft_putchar.c utils/ft_puthex_big.c utils/ft_puthex_lit.c utils/ft_putnbr_u.c utils/ft_putnbr.c utils/ft_putstr.c utils/ft_strchr.c utils/ft_puthex_p.c utils/ft_putfloat.c\
		ft_printf_utils.c ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
 
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) 

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
