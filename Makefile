NAME = test
MY_LIB = ./My_Library/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

OBJ = $(SRC:.c=.o) #les .c sont lu en .o
MY_LIBDIR = ./My_Library/

all: $(NAME)

$(NAME): $(OBJ) # $@ prends la target et $^ prends la dependance du dessus
	make -C $(MY_LIBDIR)
	$(CC) $(CFLAGS) $(OBJ) $(MY_LIB) -o $(NAME)
./src/%.o: ./src/%.c # remplace les .c par .o avec -c . $< = dependance le plus a gauche
	$(CC) $(CFLAGS) -I$(MY_LIBDIR) -c $< -o $@

.PHONY: all clean fclean re #.phony dit que ca se ne sont pas des fichiers
clean:
	rm -f $(OBJ)
	make -C $(MY_LIBDIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(MY_LIBDIR) fclean
re: fclean all
	make -C $(MY_LIBDIR) re
