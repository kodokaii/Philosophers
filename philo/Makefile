NAME 		= philo

CC 			= cc
RM			= rm -f
CLONE 		= git clone --depth=1
CFLAGS 		+= -Wall -Wextra -Werror
CLINKS		= -lpthread

SRC 		= $(wildcard *.c)

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(CLINKS)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re
