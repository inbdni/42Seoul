CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= $(wildcard srcs/*.c)
OBJS	= ${SRCS:.c=.o}
TARGET	= libft.a

.c.o:
	${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

${TARGET}:	${OBJS}
	ar rcs ${TARGET} ${OBJS}

all:	${TARGET}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${TARGET}

re:		fclean all

.PHONY:	all clean fclean re
