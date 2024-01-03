/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:34:42 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/03 15:46:45 by namoisan         ###   ########.fr       */
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
	int		moves;
	int		collectable;
}	t_game;

typedef struct s_data
{
	t_game	*game;
}	t_data;

#endif
