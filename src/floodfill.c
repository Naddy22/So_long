/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:33:56 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/25 17:56:52 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	copy_map(t_data *data)
{
	data->game.h = 0;
	data->game.copy_map = (char **)malloc((data->game.height + 1)
			* sizeof(char *));
	if (data->game.copy_map == NULL)
	{
		ft_free_table(data->game.copy_map);
		puterror("Memory allocation\n");
	}
	data->game.copy_map[data->game.height] = 0;
	while (data->game.h < data->game.height)
	{
		data->game.copy_map[data->game.h] \
		= ft_strdup(data->game.map[data->game.h]);
		data->game.h++;
	}
	data->game.copy_map[data->game.h] = NULL;
}

static void	floodfill(t_data *data, int h, int w)
{
	if (h < 0 || h >= data->game.height || w < 0 || w >= data->game.width)
		return ;
	else if (data->game.copy_map[h][w] == '1'
		|| data->game.copy_map[h][w] == 'X')
		return ;
	else if (data->game.copy_map[h][w] == 'C')
		data->game.collected++;
	else if (data->game.copy_map[h][w] == 'E')
		data->game.exit_counter++;
	data->game.copy_map[h][w] = 'X';
	floodfill(data, h + 1, w);
	floodfill(data, h, w + 1);
	floodfill(data, h - 1, w);
	floodfill(data, h, w - 1);
}

int	path_is_valid(t_data *data)
{
	copy_map(data);
	data->game.exit_counter = 0;
	floodfill(data, data->game.player_h, data->game.player_w);
	ft_free_table(data->game.copy_map);
	if (data->game.collectable == data->game.collected
		&& data->game.exit_counter == 1)
	{
		data->game.collected = 0;
		return (TRUE);
	}
	else
		return (FALSE);
}
