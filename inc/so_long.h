/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:34:42 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/10 10:42:12 by namoisan         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL 1
# define ERROR 2

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player_w;
	int		player_h;
	int		moves;
	int		collectable;
}	t_game;

typedef struct s_data
{
	t_game	game;
}	t_data;

int	check_file_name(char *file);
void	get_height(char *file, t_data *data);
void	get_map(char *file, t_data *data);
void	parsing(char *file, t_data *data);

#endif
