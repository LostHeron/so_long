/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:53:32 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 18:59:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	move_up(t_data *p_data, char **map)
{
	if (map[p_data->player.x - 1][p_data->player.y] == '0'
		|| map[p_data->player.x - 1][p_data->player.y] == 'C'
		|| map[p_data->player.x - 1][p_data->player.y] == 'P')
	{
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
		p_data->ptr_img_ground, \
		p_data->player.y * SPRITE_WIDTH, p_data->player.x * SPRITE_WIDTH);
		p_data->player.x -= 1;
		mlx_put_image_to_window(p_data->ptr_mlx, p_data->ptr_win, \
		p_data->ptr_img_player, \
		p_data->player.y * SPRITE_WIDTH, p_data->player.x * SPRITE_WIDTH);
	}
}
