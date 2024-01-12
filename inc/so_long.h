/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:34:42 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/12 12:14:49 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

//define de base
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 2

//Error
# define VALID 0
# define INVALID_RECTANGLE 3
# define INVALID_CHARS 4
# define EXIT_ERROR 5
# define PLAYER_ERROR 6
# define COLLECTABLE_ERROR 7
# define INVALID_WALL 8

//structure
typedef struct s_game
{
	char	**map;
	char	**copy_map;
	int		width;
	int		height;
	int		player_w;
	int		player_h;
	int		moves;
	int		collectable;
	int		collected;
	int		h;
	int		w;
	int		p;
	int		exit_counter;
}	t_game;

typedef struct s_data
{
	t_game	game;
}	t_data;

//parsing
int		check_file_name(char *file);
void	get_height(char *file, t_data *data);
void	get_map(char *file, t_data *data);
void	parsing(char *file, t_data *data);
void	init(t_game *game);

//utils error
void	puterror_free(char *error, t_data *data);
void	puterror(char *error);
void	show_error(int error, t_data *data);

//map et wall is valid
int	ft_wall_is_valid(t_data *data);
int	map_is_valid(t_data *data);

//floodfill
int	path_is_valid(t_data *data);
#endif
