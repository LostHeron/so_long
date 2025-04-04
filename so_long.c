/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:08:02 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:34:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_memory.h"
#include "so_long.h"
#include "parsing.h"
#include "printing.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static void	init_struct(t_data *ptr_data);
static int	check_nb_args(int argc);

int	main(int argc, char **argv)
{
	t_data	data;
	size_t	i;

	check_nb_args(argc);
	init_struct(&data);
	parsing(argv[1], &data);
	i = 0;
	while (i < data.map.size)
	{
		printf("-> %s\n", ((char **)data.map.data)[i]);
		i++;
	}
	printf("data.nb_col = %zu\n", data.nb_cols);
	printf("data.nb_line = %zu\n", data.nb_lines);
}

static int	check_nb_args(int argc)
{
	if (argc != 2)
	{
		print_error(0);
		ft_printf_fd(2, "wrong usage !\n");
		ft_printf_fd(2, "usage : ./so_long map\n");
		exit (1);
	}
	return (0);
}

static void	init_struct(t_data *ptr_data)
{
	size_t	data_size;

	data_size = sizeof(*ptr_data);
	ft_bzero(ptr_data, data_size);
}
