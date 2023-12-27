/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadege <nadege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:12:51 by namoisan          #+#    #+#             */
/*   Updated: 2023/12/27 17:05:08 by nadege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// .ber check
// forme rectangulaire check
// mur tout autour sinon erreur check sanf erreur
// 01 et C x1 minimum et PE juste x1 (erreur si doublon), voir pour les vilains apres
// verifier si chemin valide (flood fill)
//Si une erreur de configuration est détectée, le programme doit quitter proprement
// et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.

int	format_file_is_valid(char *file)
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

int	map_is_rectangle(t_data *data)
{
	int	h;
	int	len;

	h = 0;
	len = ft_strlen(data->game->map[h]);
	h++;
	while (data->game->map[h] != '\0')
	{
		if (ft_strlen(data->game->map[h]) != len)
			return (FALSE);
		h++;
	}
	if (h - 1 >= len)
		return (FALSE);
	data->game->width = len;
	data->game->height = h - 1;
	return (TRUE);
}

