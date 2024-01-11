/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:09 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/11 16:07:18 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	puterror_free(char *error, t_data *data)
{
	ft_free_table(data->game.map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	puterror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	show_error(int error, t_data *data)
{
	if (error == INVALID_RECTANGLE)
		puterror_free("Map is not rectangle\n", data);
	else if (error == INVALID_WALL)
		puterror_free("The map is not surrounded by walls\n", data);
	else if (error == INVALID_CHARS)
		puterror_free("Chars is invalid\n", data);
	else if (error == EXIT_ERROR)
		puterror_free("There is more than 1 exit\n", data);
	else if (error == PLAYER_ERROR)
		puterror_free("There is more than 1 player\n", data);
	else if (error == COLLECTABLE_ERROR)
		puterror_free("There is less than 1 collectabe\n", data);
}
