NAME = libft.a
NAME1 = server
NAME2 = client

INC = minitalk.h

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_putstr.c ft_strjoin.c ft_strlen.c ft_strdup.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC) server.c client.c
	gcc -c $(CFLAGS) $(SRC) -I $(INC) 
	ar -cr $(NAME) $(OBJ)
	gcc $(CFLAGS) server.c $(NAME) -o $(NAME1)
	gcc $(CFLAGS) client.c $(NAME) -o $(NAME2)

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME) $(NAME1) $(NAME2)

re : fclean all