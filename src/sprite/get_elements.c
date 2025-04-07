/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:42:21 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 17:44:24 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	get_ptr_ground(t_data *p_data, char *filename)
{
	int	fd;
	int	width;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (ERROR_OPEN);
	}
	p_data->ptr_img_ground = \
		mlx_xpm_file_to_image(p_data->ptr_mlx, filename, &width, &height);
	if (p_data->ptr_img_ground == NULL)
		return (ERROR_MLX);
	if (width != SPRITE_WIDTH)
		return (ERROR_SPRITE_FORMAT);
	if (height != SPRITE_HEIGHT)
		return (ERROR_SPRITE_FORMAT);
	close(fd);
	return (0);
}

int	get_ptr_wall(t_data *p_data, char *filename)
{
	int	fd;
	int	width;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (ERROR_OPEN);
	}
	p_data->ptr_img_wall = \
		mlx_xpm_file_to_image(p_data->ptr_mlx, filename, &width, &height);
	if (p_data->ptr_img_wall == NULL)
		return (ERROR_MLX);
	if (width != SPRITE_WIDTH)
		return (ERROR_SPRITE_FORMAT);
	if (height != SPRITE_HEIGHT)
		return (ERROR_SPRITE_FORMAT);
	close(fd);
	return (0);
}

int	get_ptr_player(t_data *p_data, char *filename)
{
	int	fd;
	int	width;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (ERROR_OPEN);
	}
	p_data->ptr_img_player = \
		mlx_xpm_file_to_image(p_data->ptr_mlx, filename, &width, &height);
	if (p_data->ptr_img_player == NULL)
		return (ERROR_MLX);
	if (width != SPRITE_WIDTH)
		return (ERROR_SPRITE_FORMAT);
	if (height != SPRITE_HEIGHT)
		return (ERROR_SPRITE_FORMAT);
	close(fd);
	return (0);
}

int	get_ptr_coin(t_data *p_data, char *filename)
{
	int	fd;
	int	width;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (ERROR_OPEN);
	}
	p_data->ptr_img_coin = \
		mlx_xpm_file_to_image(p_data->ptr_mlx, filename, &width, &height);
	if (p_data->ptr_img_coin == NULL)
		return (ERROR_MLX);
	if (width != SPRITE_WIDTH)
		return (ERROR_SPRITE_FORMAT);
	if (height != SPRITE_HEIGHT)
		return (ERROR_SPRITE_FORMAT);
	close(fd);
	return (0);
}

int	get_ptr_exit(t_data *p_data, char *filename)
{
	int	fd;
	int	width;
	int	height;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(filename);
		return (ERROR_OPEN);
	}
	p_data->ptr_img_exit = \
		mlx_xpm_file_to_image(p_data->ptr_mlx, filename, &width, &height);
	if (p_data->ptr_img_exit == NULL)
		return (ERROR_MLX);
	if (width != SPRITE_WIDTH)
		return (ERROR_SPRITE_FORMAT);
	if (height != SPRITE_HEIGHT)
		return (ERROR_SPRITE_FORMAT);
	close(fd);
	return (0);
}
