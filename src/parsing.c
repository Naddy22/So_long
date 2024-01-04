/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:19 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/04 14:16:48 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_file_name(char *file)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(file, '.'))
	{
		tmp = ft_strchr(file, '.');
		if (ft_strncmp(".ber", tmp, 5) == 0)
			return (TRUE);
	}
	return (FALSE);
}

void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player_h = 0;
	game->player_w = 0;
	game->moves = 0;
	game->collectable = 0;
}

// lire map:
// ouvrir fichier et recuperer le nombre de ligne avec get next line, free et fermer fichier
void	get_height(char *file, t_data *data)
{
	int fd;
	char *line;

	line = NULL;
	fd = open(file, O_RDONLY);
	// printf("avant: %d\n", data->game->height);
	if (fd < 0)
		printf("error file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		// printf("%s\n", line);
		data->game->height++;
		free(line);
		line = NULL;
	}
	// printf("apres get next line: %d\n", data->game->height);
	close(fd);
}
// malloc le nombre de ligne, rouvrir le fichier pour strdup chaque ligne dans **map, fermer fichier
void	get_map(char *file, t_data *data)
{
	int		fd;
	char	*line;
	int		h;

	line = NULL;
	h = 0;
	data->game->map = malloc((data->game->height + 1 * sizeof(char *)));
	if (data->game->map == NULL)
		printf("error malloc");
	fd = open(file, O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		data->game->map[h] = ft_strdup(line);
		h++;
		free(line);
		line = NULL;
	}
	close(fd);
}

// parsing va verifier si bon fichier, appeler les fonction, voir pour les erreur (peut être stocker
// dans un int pour derriere renvoyer la bonne erreur)
void	parsing(char *file, t_data *data)
{
	if(check_file_name(file) == TRUE)
	{
		init(data->game);
		get_height(file, data);
		get_map(file, data);
	}
}
