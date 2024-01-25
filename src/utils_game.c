/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:03:40 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/25 11:32:12 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit(t_data *data)
{
	// t_data *data;
	// data = param;
	ft_free_table(data->game.map);
	mlx_delete_image(data->mlx_win, data->mlx_img);
	mlx_terminate(data->mlx_win);
	exit(EXIT_SUCCESS);
}

void	show_moves(t_data *data)
{
	ft_putnbr_fd(data->game.moves, 1);
	if (data->game.moves < 2)
		ft_putstr_fd(" move\n", 1);
	else
		ft_putstr_fd(" moves\n", 1);
}

void	message(t_data *data, int h, int w, const char *img)
{
	(void) img;
	if (data->game.map[h][w] == 'E'
		&& data->game.collected == data->game.collectable)
	{
		ft_putstr_fd("Good job! You did it in ", 1);
		ft_putnbr_fd(data->game.moves, 1);
		ft_putstr_fd(" moves\n", 1);
		ft_exit(data);
	}
	else if (data->game.map[h][w] == 'E'
		&& data->game.collected != data->game.collectable)
	{
		// put_image(FLOOR_MIDDLE_M, data, data->game.player_h,
		// 	data->game.player_w);
		// put_image(EXIT, data, h, w);
		// put_image(img, data, h, w);
		ft_putstr_fd("You have to take all the collectables\n", 1);
	}
}
// regler le probleme ou le plaer ne peut pas passer sur l'exit si
// il a pas tous les collectables
