/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:12:51 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/25 18:01:22 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	map_is_rectangle(t_data *data)
{
	size_t	len;

	data->game.h = 0;
	len = ft_strlen(data->game.map[data->game.h]) - 1;
	if (len > 53)
		puterror_free("Width of the map is too long, max 53\n", data);
	data->game.h++;
	while (data->game.h < data->game.height)
	{
		if ((ft_strlen(data->game.map[data->game.h]) - 1) != len)
			return (FALSE);
		data->game.h++;
	}
	data->game.width = (int)len;
	return (TRUE);
}

// verifier les characteres: 01CEP
static int	check_chars(t_data *data)
{
	data->game.h = 0;
	while (data->game.h < data->game.height)
	{
		data->game.w = 0;
		while (data->game.w < data->game.width)
		{
			if (!ft_strchr("01CEP", data->game.map[data->game.h][data->game.w]))
				return (FAIL);
			data->game.w++;
		}
		data->game.h++;
	}
	return (SUCCESS);
}

// ensuite une pour voir si bien 1 seule E et P et minimum 1 C
static int	check_max_char(t_data *data)
{
	data->game.h = 0;
	while (data->game.h < data->game.height)
	{
		data->game.w = 0;
		while (data->game.w < data->game.width)
		{
			if (ft_strchr("E", data->game.map[data->game.h][data->game.w]))
				data->game.exit_counter++;
			if (ft_strchr("P", data->game.map[data->game.h][data->game.w]))
			{
				data->game.player_h = data->game.h;
				data->game.player_w = data->game.w;
				data->game.p++;
			}
			if (ft_strchr("C", data->game.map[data->game.h][data->game.w]))
				data->game.collectable++;
			data->game.w++;
		}
		data->game.h++;
	}
	if (data->game.exit_counter != 1 || data->game.p != 1
		|| data->game.collectable < 1)
		return (FAIL);
	return (SUCCESS);
}

static int	get_error_char(t_data *data)
{
	if (data->game.exit_counter != 1)
		return (EXIT_ERROR);
	if (data->game.p != 1)
		return (PLAYER_ERROR);
	if (data->game.collectable < 1)
		return (COLLECTABLE_ERROR);
	return (0);
}

int	map_is_valid(t_data *data)
{
	int	error;

	error = 0;
	if (map_is_rectangle(data) != TRUE)
		return (INVALID_RECTANGLE);
	else if (ft_wall_is_valid(data) != TRUE)
		return (INVALID_WALL);
	else if (check_chars(data) != SUCCESS)
		return (INVALID_CHARS);
	else if (check_max_char(data) != SUCCESS)
	{
		error = get_error_char(data);
		return (error);
	}
	return (VALID);
}
