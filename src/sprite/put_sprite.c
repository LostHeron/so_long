/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:02:14 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 17:47:52 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	put_sprite_single(t_data *p_data, int line_i, int col_i);

int	put_sprite(t_data *p_data)
{
	size_t	line_i;
	size_t	col_i;

	line_i = 0;
	while (line_i < p_data->nb_lines)
	{
		col_i = 0;
		while (col_i < p_data->nb_cols)
		{
			put_sprite_single(p_data, line_i, col_i);
			col_i++;
		}
		line_i++;
	}
	return (0);
}

static void	put_sprite_single(t_data *p_data, int line_i, int col_i)
{
	if (((char **)p_data->map.data)[line_i][col_i] == 'P')
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
	p_data->ptr_img_player, col_i * SPRITE_WIDTH, line_i * SPRITE_HEIGHT);
	else if (((char **)p_data->map.data)[line_i][col_i] == '0')
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
	p_data->ptr_img_ground, col_i * SPRITE_HEIGHT, line_i * SPRITE_WIDTH);
	else if (((char **)p_data->map.data)[line_i][col_i] == '1')
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
	p_data->ptr_img_wall, col_i * SPRITE_HEIGHT, line_i * SPRITE_WIDTH);
	else if (((char **)p_data->map.data)[line_i][col_i] == 'C')
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
	p_data->ptr_img_coin, col_i * SPRITE_HEIGHT, line_i * SPRITE_WIDTH);
	else if (((char **)p_data->map.data)[line_i][col_i] == 'E')
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
	p_data->ptr_img_exit, col_i * SPRITE_HEIGHT, line_i * SPRITE_WIDTH);
}
