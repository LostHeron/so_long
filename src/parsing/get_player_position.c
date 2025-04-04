/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:24:28 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:27:31 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_data *ptr_data)
{
	size_t	line_i;
	size_t	col_i;
	char	**map;

	line_i = 0;
	map = ptr_data->map.data;
	while (line_i < ptr_data->nb_lines)
	{
		col_i = 0;
		while (col_i < ptr_data->nb_cols)
		{
			if (map[line_i][col_i] == 'P')
			{
				ptr_data->player.x = line_i;
				ptr_data->player.y = col_i;
			}
			col_i++;
		}
		line_i++;
	}
}
