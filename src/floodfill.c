/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:33:56 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/12 12:12:56 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	copy_map(t_data *data)
{
	data->game.h = 0;
	data->game.copy_map = (char **)malloc((data->game.height + 1)
			* sizeof(char *));
	if (data->game.copy_map == NULL)
		puterror_free("Memory allocation\n", data);
	while (data->game.h < data->game.height)
	{
		data->game.copy_map[data->game.h] = ft_strdup(data->game.map[data->game.h]);
		data->game.h++;
	}
}

static void	floodfill(t_data *data, int h, int w)
{
	data->game.exit_counter = 0;
	if (data->game.copy_map[h][w] == '1' || data->game.copy_map[h][w] == 'X')
		return ;
	if (data->game.copy_map[h][w] == 'C')
	{
		data->game.collected++;
		data->game.copy_map[h][w] = 'X';
	}
	else if (data->game.copy_map[h][w] == 'E')
	{
		data->game.exit_counter++;
		data->game.copy_map[h][w] = 'X';
	}
	floodfill(data, h + 1, w);
	floodfill(data, h, w + 1);
	floodfill(data, h - 1, w);
	floodfill(data, h, w - 1);
}
int	path_is_valid(t_data *data)
{
	floodfill(data, data->game.player_h, data->game.player_w);
	if (data->game.collectable == data->game.collected
		&& data->game.exit_counter == 1)
		return (TRUE);
	else
		return (FALSE);
}
