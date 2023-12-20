NAME = test
MY_LIB = ./libft/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

OBJ = $(SRC:.c=.o) #les .c sont lu en .o
MY_LIBDIR = ./libft/

all: $(NAME)

$(NAME): $(OBJ) # $@ prends la target et $^ prends la dependance du dessus
	make -C $(MY_LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) $(MY_LIB) -o $(NAME)
./src/%.o: ./src/%.c # remplace les .c par .o avec -c . $< = dependance le plus a gauche
	$(CC) $(CFLAGS) -I$(MY_LIBDIR) -c $< -o $@

clean:
	make -C $(MY_LIBDIR) clean
	rm -f $(OBJ)
fclean: clean
	make -C $(MY_LIBDIR) fclean
	rm -f $(NAME)
re:	fclean all
#make -C $(MY_LIBDIR)
.PHONY: all clean fclean re #.phony dit que ca se ne sont pas des fichiers
