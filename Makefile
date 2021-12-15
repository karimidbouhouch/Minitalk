NAME = libft.a
SERVER = server
CLIENT = client

INC = minitalk.h

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_putstr.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(INC) server.c client.c
	gcc -c $(CFLAGS) $(SRC) -I $(INC) 
	ar -cr $(NAME) $(OBJ)
	gcc $(CFLAGS) server.c $(NAME) -o $(SERVER)
	gcc $(CFLAGS) client.c $(NAME) -o $(CLIENT)

bonus :
	gcc -c $(CFLAGS) $(SRC) -I $(INC) 
	ar -cr $(NAME) $(OBJ)
	gcc $(CFLAGS) server_bonus.c $(NAME) -o $(SERVER)
	gcc $(CFLAGS) client_bonus.c $(NAME) -o $(CLIENT)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME) $(SERVER) $(CLIENT)

re : fclean all