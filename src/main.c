/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:23:28 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/04 13:37:04 by namoisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;
	int	h;

	h = 0;

	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		data.game = malloc(sizeof(t_game));
		if (data.game == NULL)
			printf("error malloc data.game");
		parsing(argv[1], &data);
	}
	while (h < data.game->height)
	{
		printf("%s", data.game->map[h]);
		h++;
	}
	return (0);
}
