/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:19:04 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/19 10:58:55 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// mlx
// 1 donner la taille à mes tailles windows, stocker mlx init dans *mlx, mlx new
// windows dans mlx win (free si l'un d'eux est NULL apres avoir stocker)
// 2 faire en sorte de mettre toutes les images sur la map (display img)
// 3 voir pour key hook (player key pour bouger le perso en fonction de WASD
// et fleche ou esc ou croix(voir pour une fonction qui exit tout))
// message ou autre en fonction de ce qu'il se passe (pas tous les collectable quand on
// va sur exit, return si mur, si 0 remettre sol et player à la place. si collectable
// enlever image du collectable, remettre la case sur 0 et rajouter un collectable collecté)
// remettre les données du player à jours et rajouter un mouvement fait puis l'imprimer
// dans le terminal(voir pour fonction appart).
// hook, puis loop

void mlx(t_data *data)
{
	int win_h;
	int win_w;

	win_h = data->game.height * IMG_SIZE;
	win_w = data->game.width * IMG_SIZE;
	data->mlx_win = mlx_init(win_w, win_h, "So Long", true);
	if (data->mlx_win == NULL)
		puterror_free("MLX init", data);
	display_image(data);
	// mlx_loop_hook(data->mlx_win, ft_exit, data);
	mlx_loop(data->mlx_win);
	// delete texture et image
	mlx_terminate(data->mlx_win);
}
