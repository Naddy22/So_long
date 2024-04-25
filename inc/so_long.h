/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:34:42 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/12 14:36:20 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// define de base
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 2

// Error
# define VALID 0
# define INVALID_RECTANGLE 3
# define INVALID_CHARS 4
# define EXIT_ERROR 5
# define PLAYER_ERROR 6
# define COLLECTABLE_ERROR 7
# define INVALID_WALL 8

// Image
# define IMG_SIZE 48

# define FLOOR_TOP_L "image/floor/floortopleft.png"
# define FLOOR_TOP_M "image/floor/floortopmiddle.png"
# define FLOOR_TOP_R "image/floor/floortopright.png"
# define FLOOR_MIDDLE_L "image/floor/floormiddleleft.png"
# define FLOOR_MIDDLE_M "image/floor/floormiddlemiddle.png"
# define FLOOR_MIDDLE_R "image/floor/floormiddleright.png"
# define FLOOR_DOWN_L "image/floor/floordownleft.png"
# define FLOOR_DOWN_M "image/floor/floordownmiddle.png"
# define FLOOR_DOWN_R "image/floor/floordownright.png"

# define WALL "image/wall/brush_wall.png"

# define COLLECTABLE "image/collectable/collectable.png"

# define EXIT "image/exit/exit.png"

# define PLAYER_FACE "image/player/playerface.png"
# define PLAYER_BACK "image/player/playerback.png"
# define PLAYER_RIGHT "image/player/playerright.png"
# define PLAYER_LEFT "image/player/playerleft.png"

// structure
typedef struct s_game
{
	char			**map;
	char			**copy_map;
	int				width;
	int				height;
	int				player_w;
	int				player_h;
	int				moves;
	int				collectable;
	int				collected;
	int				h;
	int				w;
	int				p;
	int				exit_counter;
}					t_game;

typedef struct s_data
{
	t_game			game;
	mlx_t			*mlx_win;
	mlx_texture_t	*mlx_texture;
	mlx_image_t		*mlx_img;
}					t_data;

// parsing
int					check_file_name(char *file);
void				get_height(char *file, t_data *data);
void				get_map(char *file, t_data *data);
void				parsing(char *file, t_data *data);
void				init(t_game *game);

// utils error
void				puterror_free(char *error, t_data *data);
void				puterror(char *error);
void				show_error(int error, t_data *data);

// map et wall is valid
int					ft_wall_is_valid(t_data *data);
int					map_is_valid(t_data *data);

// floodfill
int					path_is_valid(t_data *data);

// mlx
void				mlx(t_data *data);

// display_img
void				display_image(t_data *data);
void				put_image(const char *img, t_data *data, int h, int w);

// utils_game
void				ft_exit(t_data *data);
void				show_moves(t_data *data);
void				message(t_data *data, int h, int w, const char *img);
void				check_last_position(t_data *data, int h, int w,
						const char *img);

#endif
