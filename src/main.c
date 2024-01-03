/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoisan <namoisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:23:28 by namoisan          #+#    #+#             */
/*   Updated: 2024/01/03 14:42:00 by namoisan         ###   ########.fr       */
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

	if (argc == 2)
	{
		parsing(argv[1], &data);
	}
}
