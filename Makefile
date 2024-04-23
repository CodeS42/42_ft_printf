SRCS =	srcs/main.c \
		srcs/print.c \
		srcs/putnbr.c \
		srcs/hexa.c \

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

INCLUDES = headers

all : $(NAME) 

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

.c.o :
	cc -Wall -Wextra -Werror -I $(INCLUDES) -c $< -o $(<:.c=.o)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
