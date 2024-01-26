NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

MY_LIB = ./libft/libft.a
MY_LIBDIR = ./libft/

# MLX42
MLXDIR = ./MLX42
HEADERS = -I ./include -I $(MLXDIR)/include
LIBS = $(MLXDIR)/build/libmlx42.a -ldl -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
LIBMLX = $(MLXDIR)/build/libmlx42.a

DEPS = ./inc/so_long.h
MK = mkdir -p
RM = rm -rf
BIN = bin
SRC = main.c parsing.c ft_map_is_valid.c ft_wall_is_valid.c utils_error.c floodfill.c \
mlx.c display_img.c utils_game.c
SDIR = ./src/

# -- COLORS -- #
BLACK=\033[0;30m# Black
RED=\033[0;31m# Red
GREEN=\033[0;32m# GREEN
YELLOW=\033[0;33m# YELLOW
BLUE=\033[0;34m# BLUE
PURPLE=\033[0;35m# PURPLE
CYAN=\033[0;36m# CYAN
WHITE=\033[0m# WHITE

_OBJ = $(SRC:.c=.o) #les .c sont lu en .o

OBJ= $(addprefix $(BIN)/, $(_OBJ))

all: dependdown $(LIBMLX) $(NAME)

# install brew, cmake and glfw
dependdown:
	@if [ -x "$$HOME/homebrew/bin/brew" ] || [ -x "$$HOME/.brew/bin/brew" ]; then \
		echo "$(GREEN)✔︎ $(ITALIC)Brew is already installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
	else \
		echo "$(RED)✗ $(ITALIC)Brew not found$(RESET)$(RED) ✗"; \
		read -p "Do you want to install brew? y/n: "  brewchoice; \
		printf "$(RESET)"; \
		if [ "$$brewchoice" = "y" ]; then \
			rm -rf $$HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $$HOME/.brew && \
			echo 'export PATH=$$HOME/.brew/bin:$$PATH' >> $$HOME/.zshrc && source $$HOME/.zshrc && brew update; \
			echo "$(GREEN)✔︎ $(ITALIC)Brew successfully installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
		else \
			echo "Exit"; \
			exit 2; \
		fi \
	fi
	@if [ -d "$$HOME/homebrew/opt/cmake/bin" ] || [ -d "$$HOME/.brew/opt/cmake/bin" ]; then \
		echo "$(GREEN)✔︎ $(ITALIC)cmake is already installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
	else \
		echo "$(RED)✗ $(ITALIC)cmake not found$(RESET)$(RED) ✗"; \
		read -p "Do you want to install cmake? y/n: " cmakechoice; \
		printf "$(RESET)"; \
		if [ "$$cmakechoice" = "y" ]; then \
			brew install cmake; \
			echo "$(GREEN)✔︎ $(ITALIC)cmake successfully installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
		else \
			echo "Exit"; \
			exit 2; \
		fi \
	fi
	@if [ -d "$$HOME/homebrew/opt/glfw/lib" ] || [ -d "$$HOME/.brew/opt/glfw/lib" ]; then \
		echo "$(GREEN)✔︎ $(ITALIC)glfw is already installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
	else \
		echo "$(RED)✗ $(ITALIC)glfw not found$(RESET)$(RED) ✗"; \
		read -p "Do you want to install glfw? y/n: " glfwchoice; \
		printf "$(RESET)"; \
		if [ "$$glfwchoice" = "y" ]; then \
			brew install glfw; \
			echo "$(GREEN)✔︎ $(ITALIC)glfw successfully installed$(RESET)$(GREEN) ✔︎$(RESET)"; \
		else \
			echo "Exit"; \
			exit 2; \
		fi \
	fi

$(LIBMLX):
	@cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(NAME): $(BIN) $(OBJ) # $@ prends la target et $^ prends la dependance du dessus
	@make -C $(MY_LIBDIR)
	@$(CC) $(CFLAGS) $(OBJ) $(MY_LIB) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)So_Long compilation OK$(WHITE)"

$(BIN): #crée dossier bin
	@$(MK) $(BIN)

$(BIN)/%.o: ./src/%.c $(DEPS) # remplace les .c par .o avec -c . $< = dependance le plus a gauche
	@$(CC) -c -o $@ $< -I$(MY_LIBDIR) $(CFLAGS) $(HEADERS)

.PHONY: all clean fclean re libmlx #.phony dit que ca se ne sont pas des fichiers

clean:
	@make -C $(MY_LIBDIR) clean
	@$(RM) $(BIN)
	@$(RM) $(MLXDIR)/build
	@echo "$(RED)So_long object files deleted$(WHITE)"

fclean: clean
	@make -C $(MY_LIBDIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)So_long object files and executable deleted$(WHITE)"

re:	fclean all
