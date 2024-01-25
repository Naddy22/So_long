/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:19 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/25 10:16:13 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_file_name(char *file)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strrchr(file, '.'))
	{
		tmp = ft_strrchr(file, '.');
		if (ft_strncmp(".ber", tmp, 5) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	init(t_game *game)
{
	game->map = NULL;
	game->copy_map = NULL;
	game->width = 0;
	game->height = 0;
	game->player_h = 0;
	game->player_w = 0;
	game->moves = 0;
	game->collectable = 0;
	game->collected = 0;
	game->h = 0;
	game->w = 0;
	game->exit_counter = 0;
	game->p = 0;
}

// lire map:
// ouvrir fichier et recuperer le nombre de ligne avec get next line,
// free et fermer fichier
void	get_height(char *file, t_data *data)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		puterror("File opening\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game.height++;
		free(line);
		line = NULL;
	}
	if (data->game.height > 27)
		puterror_free("Height of the map is too long, max 27\n", data);
	// printf("%d\n", data->game.height);
	close(fd);
}
// malloc le nombre de ligne,
// rouvrir le fichier pour strdup chaque ligne dans **map, fermer fichier
void	get_map(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		h;

	line = NULL;
	h = 0;
	data->game.map = malloc((data->game.height + 1) * sizeof(char *));
	if (data->game.map == NULL)
		puterror_free("Memory allocation\n", data);
	data->game.map[data->game.height] = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		puterror("File opening\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->game.map[h] = ft_strdup(line);
		h++;
		free(line);
		line = NULL;
	}
	close(fd);
}

// parsing va verifier si bon fichier, appeler les fonction,
// voir pour les erreur (peut être stocker
// dans un int pour derriere renvoyer la bonne erreur)
void	parsing(char *file, t_data *data)
{
	int	error;

	error = 0;
	ft_bzero(data, sizeof(t_data));
	if (check_file_name(file) == TRUE)
	{
		init(&data->game);
		get_height(file, data);
		if (data->game.height == 0)
			puterror("The map is empty\n");
		get_map(file, data);
		error = map_is_valid(data);
		if (error > 0)
			show_error(error, data);
		if (path_is_valid(data) != TRUE)
			puterror("Path is invalid\n");
	}
	else
		puterror("Invalid file\n");
}
