SRCS		= 	srcs/main.c \
				srcs/ft_atod.c \
				srcs/ft_display.c \
				srcs/ft_file.c \
				srcs/ft_matrix.c \
				srcs/ft_obj.c \
				srcs/ft_transform.c

OBJS		=	$(SRCS:.c=.o)

INC			=	includes

NAME		=	basic3d

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

SDL			=	-lSDL2 `sdl2-config --cflags --libs`

MATH		=	-lm

HEADERS		=	-I $(INC)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEADERS)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(MATH) $(SDL)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
