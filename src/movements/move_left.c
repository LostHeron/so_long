/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:55:04 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 18:59:17 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	move_left(t_data *p_data, char **map)
{
	if (map[p_data->player.x][p_data->player.y - 1] == '0'
		|| map[p_data->player.x][p_data->player.y - 1] == 'C'
		|| map[p_data->player.x][p_data->player.y - 1] == 'P')
	{
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
		p_data->ptr_img_ground, \
		p_data->player.y * SPRITE_WIDTH, p_data->player.x * SPRITE_WIDTH);
		p_data->player.y -= 1;
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
		p_data->ptr_img_player, \
		p_data->player.y * SPRITE_WIDTH, p_data->player.x * SPRITE_WIDTH);
	}
}
