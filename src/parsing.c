/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:27:19 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/03 16:17:40 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_file_name(char *file)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr(file, "."))
	{
		tmp = ft_strchr(file, ".");
		if (ft_strncmp(".ber", tmp, 5) == 0)
			return (TRUE);
	}
	return (FALSE);
}
// lire map:
// ouvrir fichier et recuperer le nombre de ligne avec get next line, free et fermer fichier
int	get_height(char *file, t_data *data)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		printf("error");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		data->game->height++;
		free(line);
		line = NULL;
	}
	close(fd);
}
// malloc le nombre de ligne, rouvrir le fichier pour strdup chaque ligne dans **map, fermer fichier
// parsing va verifier si bon fichier, appeler les fonction, voir pour les erreur (peut être stocker
// dans un int pour derriere renvoyer la bonne erreur)
int	get_map()
{

}

int	parsing(char *argv, t_data *data)
{
	if(check_file_name == TRUE)
	{
		get_map();
	}
}
