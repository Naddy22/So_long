/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:19:04 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/20 16:48:27 by namoisan         ###   ########.fr       */
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

// passer par chaque caractere 1 et 0, E si tous les C, C en supprimant C .
void	move(int h, int w, t_data *data, const char *img)
{
	if (data->game.map[h][w] == '1')
		return ;
	else if (data->game.map[h][w] == '0')
	{
		put_image(img, data, h, w);
	}
	if (data->game.map[h][w] == 'E' && data->game.collected == data->game.collectable)
	{

	}
	data->game.player_h = h;
	data->game.player_w = w;
	data->game.moves++;
}

void	player_key(mlx_key_data_t keydata, void *param)
{
	t_data *data;
	int h;
	int w;

	data = param;
	h = data->game.player_h;
	w = data->game.player_w;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			put_image(FLOOR_MIDDLE_M, data, h, w);
			move(h - 1, w, data, PLAYER_BACK);
		}
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			put_image(FLOOR_MIDDLE_M, data, h, w);
			move(h, w - 1, data, PLAYER_LEFT);
		}
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			put_image(FLOOR_MIDDLE_M, data, h, w);
			move(h + 1, w, data, PLAYER_FACE);
		}
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			put_image(FLOOR_MIDDLE_M, data, h, w);
			move(h, w + 1, data, PLAYER_RIGHT);
		}
		// else if (keydata.key == MLX_KEY_ESCAPE)
	}
}

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
	mlx_key_hook(data->mlx_win, player_key, data);
	// mlx_loop_hook(data->mlx_win, ft_exit, data);
	mlx_loop(data->mlx_win);
	// delete texture et image
	mlx_terminate(data->mlx_win);
}

// next step : voir pour faire player_key grace à https://github.com/codam-coding-college/MLX42/blob/master/docs/Hooks.md
// https://github.com/wdelaros/so_long/blob/master/so_long.c
