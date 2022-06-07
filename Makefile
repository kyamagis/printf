CC = cc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = ft_printf.c\
			ft_put_num.c\

MAN_OBJS = $(MANDATORY:.c=.o)
BON_OBJS = $(BONUS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)

clean:
	rm -f $(MAN_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re