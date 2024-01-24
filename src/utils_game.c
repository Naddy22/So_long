/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:03:40 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/24 12:45:12 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_exit(t_data *data)
{
	// t_data *data;

	// data = param;

	mlx_delete_texture(data->mlx_texture);
	mlx_delete_image(data->mlx_win, data->mlx_img);
	mlx_terminate(data->mlx_win);
	ft_free_table(data->game.map);
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
