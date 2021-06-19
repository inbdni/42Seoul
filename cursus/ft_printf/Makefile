NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra	-Werror -c
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c print.c put.c info.c utils1.c utils2.c
OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY:	all bonus clean fclean re
