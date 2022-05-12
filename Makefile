CC = gcc
CFLAGS = -Wall -Wextra -Werror
MANDATORY = ft_printf.c\
			ft_put_num.c\
			ft_put_unchar.c\
			ft_putstr.c\
			ft_strlen.c\

#BONUS = 

MAN_OBJS = $(MANDATORY:.c=.o)
BON_OBJS = $(BONUS:.c=.o)
NAME = libftprintf.a

#ifdef WITH_BONUS
#MAN_OBJS += $(BON_OBJS)
#endif

all: $(NAME)

$(NAME): $(MAN_OBJS)
	ar r $(NAME) $(MAN_OBJS)

# bonus:
# 	make all WITH_BONUS=1

clean:
	rm -f $(MAN_OBJS) $(BON_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus