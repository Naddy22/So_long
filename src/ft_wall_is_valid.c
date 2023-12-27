/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wall_is_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadege <nadege@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:08:51 by namoisan          #+#    #+#             */
/*   Updated: 2023/12/27 15:57:51 by nadege           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_wall_is_valid(t_data *data)
{
	int	h;
	int	w;
	int	width;
	int	height;

	w = 0;
	h = 0;
	width = data->game->width;
	height = data->game->height;
	while (h < height)
	{
		if (data->game->map[h][0] != 1 || data->game->map[h][width - 1] != 1)
			return (FALSE);
		h++;
	}
	while (w < width)
	{
		if (data->game->map[0][w] != 1 || data->game->map[height - 1][w] != 1)
			return (FALSE);
		w++;
	}
	return (TRUE);
}