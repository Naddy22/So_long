/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:12:51 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/03 14:29:05 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// .ber check
// Mettre map dans char** map
// forme rectangulaire check
// mur tout autour sinon erreur check sauf erreur
// 01 et C x1 minimum et PE juste x1 (mettre de côté la position et le nom d’item à collecter)(erreur si doublon), voir pour les vilains apres
// verifier si chemin valide (flood fill)
//Si une erreur de configuration est détectée, le programme doit quitter proprement
// et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.

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
