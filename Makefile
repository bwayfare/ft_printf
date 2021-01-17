CC      =		gcc

LIB     =		ar rc

DIR     =		./

HEADER  =		ft_printf.h

FLAGS   =		-Wall -Werror -Wextra

NAME    =		libftprintf.a

RM      =		rm -f

SRCS	=		$(DIR)ft_calloc.c\
				$(DIR)ft_hexproc.c\
				$(DIR)ft_longtoa.c\
				$(DIR)ft_printtype.c\
				$(DIR)ft_atoi.c\
				$(DIR)ft_check.c\
				$(DIR)ft_intproc.c\
				$(DIR)ft_printchar.c\
				$(DIR)ft_printint.c\
				$(DIR)ft_strlen.c\
				$(DIR)ft_bzero.c\
				$(DIR)ft_hexprint.c\
				$(DIR)ft_itoa.c\
				$(DIR)ft_printf.c\
				$(DIR)ft_printstring.c\
				$(DIR)ft_ponpoc.c

OBJS    =		$(SRCS:.c=.o)

.c.o:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADER)
					$(LIB) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

so:				$(OBJS)
					$(CC) -o libftprintf.so $(OBJS) -shared

bonus:			$(OBJS)
					$(LIB) $(NAME) $(OBJS)

.PHONY:			all clean fclean re
