/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:23:28 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/18 15:56:22 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		h;

	h = 0;
	if (argc == 2)
	{
		parsing(argv[1], &data);
		mlx(&data);
	}
	else
		puterror("The number of arguments must be equal to 1");
	// while (h < data.game.height)
	// {
	// 	printf("%s", data.game.map[h]);
	// 	h++;
	// }
	return (0);
}
