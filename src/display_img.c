/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:48:51 by namoisan          #+#    #+#             */
/*   Updated: 2024/03/21 15:09:11 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_image(const char *img, t_data *data, int h, int w)
{
	data->mlx_texture = mlx_load_png(img);
	if (data->mlx_texture == NULL)
		puterror_free("PNG image not found", data);
	data->mlx_img = mlx_texture_to_image(data->mlx_win, data->mlx_texture);
	mlx_delete_texture(data->mlx_texture);
	if (data->mlx_img == NULL)
		puterror_free("PNG image not found", data);
	mlx_image_to_window(data->mlx_win, data->mlx_img, w * IMG_SIZE, h
		* IMG_SIZE);
}

// put object pour put img pour chaque lettre differente
// (player en position P etc..)
static void	put_object(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game.height)
	{
		w = 0;
		while (w < data->game.width)
		{
			if (data->game.map[h][w] == '1')
				put_image(WALL, data, h, w);
			if (data->game.map[h][w] == 'C')
				put_image(COLLECTABLE, data, h, w);
			if (data->game.map[h][w] == 'E')
				put_image(EXIT, data, h, w);
			if (data->game.map[h][w] == 'P')
			{
				put_image(PLAYER_FACE, data, h, w);
				data->game.map[h][w] = '0';
			}
			w++;
		}
		h++;
	}
}

static void	get_floor(t_data *data, int h, int w)
{
	if (h == 0 && w == 0)
		put_image(FLOOR_TOP_L, data, 0, 0);
	else if (h == 0 && w == data->game.width - 1)
		put_image(FLOOR_TOP_R, data, 0, data->game.width - 1);
	else if (h == data->game.height - 1 && w == 0)
		put_image(FLOOR_DOWN_L, data, data->game.height - 1, 0);
	else if (h == data->game.height - 1 && w == data->game.width - 1)
		put_image(FLOOR_DOWN_R, data, data->game.height - 1, data->game.width
			- 1);
	else if (h == 0)
		put_image(FLOOR_TOP_M, data, 0, w);
	else if (h == data->game.height - 1)
		put_image(FLOOR_DOWN_M, data, data->game.height - 1, w);
	else if (w == 0)
		put_image(FLOOR_MIDDLE_L, data, h, 0);
	else if (w == data->game.width - 1)
		put_image(FLOOR_MIDDLE_R, data, h, data->game.width - 1);
	else
		put_image(FLOOR_MIDDLE_M, data, h, w);
}

static void	put_background(t_data *data)
{
	int	h;
	int	w;

	h = 0;
	while (h < data->game.height)
	{
		w = 0;
		while (w < data->game.width)
		{
			get_floor(data, h, w);
			w++;
		}
		h++;
	}
}

void	display_image(t_data *data)
{
	put_background(data);
	put_object(data);
}
