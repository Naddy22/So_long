/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:17:09 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/10 14:49:08 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	puterror_free(char *error, t_data *data)
{
	ft_free_table(&data->game.map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}

void	puterror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit(1);
}
