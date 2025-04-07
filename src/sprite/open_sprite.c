/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:35:58 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 17:45:40 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "sprite.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int		copy_bg_ground_player(t_data *ptr_data);
void	copy_values(char *dest, char *src, int nb_bytes_tot);

int	open_sprite(t_data *ptr_data)
{
	int	ret;

	ret = get_ptr_ground(ptr_data, ".assets/GROUND.xpm");
	if (ret != 0)
		return (ret);
	ret = get_ptr_wall(ptr_data, ".assets/WALL.xpm");
	if (ret != 0)
		return (ret);
	ret = get_ptr_player(ptr_data, ".assets/PLAYER.xpm");
	if (ret != 0)
		return (ret);
	ret = get_ptr_coin(ptr_data, ".assets/COIN.xpm");
	if (ret != 0)
		return (ret);
	ret = get_ptr_exit(ptr_data, ".assets/DOOR.xpm");
	if (ret != 0)
		return (ret);
	copy_bg_ground_player(ptr_data);
	return (0);
}

int	copy_bg_ground_player(t_data *ptr_data)
{
	char	*ground_addr;
	char	*player_addr;
	char	*coin_addr;
	int		bs;
	int		sl;

	ground_addr = mlx_get_data_addr(ptr_data->ptr_img_ground, &bs, &sl, &bs);
	if (ground_addr == NULL)
		return (ERROR_MLX);
	player_addr = mlx_get_data_addr(ptr_data->ptr_img_player, &bs, &sl, &bs);
	if (player_addr == NULL)
		return (ERROR_MALLOC);
	coin_addr = mlx_get_data_addr(ptr_data->ptr_img_coin, &bs, &sl, &bs);
	if (player_addr == NULL)
		return (ERROR_MALLOC);
	copy_values(player_addr, ground_addr, sl * SPRITE_HEIGHT);
	copy_values(coin_addr, ground_addr, sl * SPRITE_HEIGHT);
	return (0);
}

void	copy_values(char *dest, char *src, int nb_bytes_tot)
{
	int	i;

	i = 0;
	while (i < nb_bytes_tot)
	{
		if (dest[i] == 0)
		{
			dest[i] = src[i];
		}
		i++;
	}
}
