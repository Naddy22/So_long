NAME = So_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

# MLX42
MLXDIR = ./MLX42
HEADERS = -I ./include -I $(MLXDIR)/include
LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm

DEPS = ./inc/so_long.h

MK = mkdir -p
RM = rm -rf
BIN = bin
SRC = main.c parsing.c ft_map_is_valid.c ft_wall_is_valid.c utils_error.c floodfill.c \
mlx.c display_img.c utils_game.c
SDIR = ./src/

# -- COLORS -- #
Black=\033[0;30m # Black
Red=\033[0;31m # Red
Green=\033[0;32m # Green
Yellow=\033[0;33m # Yellow
Blue=\033[0;34m # Blue
Purple=\033[0;35m # Purple
Cyan=\033[0;36m # Cyan
White=\033[0m # White

_OBJ = $(SRC:.c=.o) #les .c sont lu en .o

OBJ= $(addprefix $(BIN)/, $(_OBJ))

all: libmlx $(NAME)

libmlx:
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(NAME): $(BIN) $(OBJ) # $@ prends la target et $^ prends la dependance du dessus
	@make -C $(MY_LIBDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MY_LIB) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(Green)So_Long compilation OK$(White)"

$(BIN): #crée dossier bin
	@$(MK) $(BIN)

$(BIN)/%.o: ./src/%.c $(DEPS) # remplace les .c par .o avec -c . $< = dependance le plus a gauche
	@$(CC) -c -o $@ $< -I$(MY_LIBDIR) $(CFLAGS) $(HEADERS)

.PHONY: all clean fclean re libmlx #.phony dit que ca se ne sont pas des fichiers

clean:
	@make -C $(MY_LIBDIR) clean
	@$(RM) $(BIN)
	@$(RM) $(LIBMLX)/build
	@echo "So_long object files deleted"

fclean: clean
	@make -C $(MY_LIBDIR) fclean
	@$(RM) $(NAME)
	@echo "So_long object files and executable deleted"

re:	fclean all
