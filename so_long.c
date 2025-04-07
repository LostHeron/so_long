/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:08:02 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 19:04:43 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_memory.h"
#include "so_long.h"
#include "ft_vectors.h"
#include "mlx.h"
#include "parsing.h"
#include "printing.h"
#include "sprite.h"
#include "movements.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100

static void	init_struct(t_data *ptr_data);
static int	check_nb_args(int argc);
static int	my_hook(int keycodes, t_data *p_data);

int	main(int argc, char **argv)
{
	t_data	data;

	check_nb_args(argc);
	init_struct(&data);
	parsing(argv[1], &data);
	data.ptr_mlx = mlx_init();
	if (data.ptr_mlx == NULL)
		return (ERROR_MLX);
	open_sprite(&data);
	data.ptr_win = mlx_new_window(data.ptr_mlx, data.nb_lines * SPRITE_WIDTH, \
								data.nb_cols * SPRITE_HEIGHT, "so_long");
	if (data.ptr_win == NULL)
		return (ERROR_MLX);
	put_sprite(&data);
	mlx_key_hook(data.ptr_win, &my_hook, &data);
	mlx_loop(data.ptr_mlx);
	//mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param)
	mlx_destroy_image(data.ptr_mlx, data.ptr_img_wall);
	mlx_destroy_image(data.ptr_mlx, data.ptr_img_ground);
	mlx_destroy_image(data.ptr_mlx, data.ptr_img_player);
	mlx_destroy_image(data.ptr_mlx, data.ptr_img_exit);
	mlx_destroy_image(data.ptr_mlx, data.ptr_img_coin);
	mlx_destroy_display(data.ptr_mlx);
	free(data.ptr_mlx);
	ft_vector_free(&data.map);
}

int	my_hook(int keycodes, t_data *p_data)
{
	printf("on est la\n");
	printf("keycodes = %i\n", keycodes);
	printf("nb_lines = %zu\n", p_data->nb_lines);
	printf("nb_cols = %zu\n", p_data->nb_cols);
	printf("p_data->player.x = %i\n", p_data->player.x);
	printf("p_data->player.y = %i\n", p_data->player.y);
	for (size_t i = 0; i < p_data->nb_lines; i++)
	{
		printf("%s\n", ((char **)p_data->map.data)[i]);
	}
	if (keycodes == UP)
		move_up(p_data, p_data->map.data);
	if (keycodes == DOWN)
		move_down(p_data, p_data->map.data);
	if (keycodes == LEFT)
		move_left(p_data, p_data->map.data);
	if (keycodes == RIGHT)
		move_right(p_data, p_data->map.data);
	if (keycodes == 65307)
	{
		mlx_loop_end(p_data->ptr_mlx);
		mlx_destroy_window(p_data->ptr_mlx, p_data->ptr_win);
	}
	return (0);
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
