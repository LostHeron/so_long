/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:08:02 by jweber            #+#    #+#             */
/*   Updated: 2025/04/02 19:49:12 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "so_long.h"
#include <stdlib.h>

static void	print_error(void);
static void	init_struct(t_data *ptr_data);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		print_error();
		ft_printf_fd(2, "wrong usage !\n");
		ft_printf_fd(2, "usage : ./so_long map\n");
	}
	init_struct(&data);
	//parse_map(argv[1], &data);
}

static void	init_struct(t_data *ptr_data)
{
	ptr_data->map = NULL;
}

static void	print_error(void)
{
	ft_printf_fd(2, "Error\n");
}
