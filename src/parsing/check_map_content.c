/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:06:46 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:29:13 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_nb_elem(int nb_player, int nb_exit, int nb_collectible);
static int	check_char(char c, int *nb_player, int *nb_exit, int *nb_collec);

int	check_map_content(t_data *ptr_data)
{
	size_t	line_i;
	size_t	col_i;
	int		nb_player;
	int		nb_exit;
	int		nb_collectible;

	line_i = 0;
	nb_player = 0;
	nb_exit = 0;
	nb_collectible = 0;
	while (line_i < ptr_data->nb_lines)
	{
		col_i = 0;
		while (col_i < ptr_data->nb_cols)
		{
			if (check_char(((char **)ptr_data->map.data)[line_i][col_i],
					&nb_player, &nb_exit, &nb_collectible) != 0)
				return (ERROR_MAP_FORMAT);
			col_i++;
		}
		line_i++;
	}
	if (check_nb_elem(nb_player, nb_exit, nb_collectible) != 0)
		return (ERROR_MAP_FORMAT);
	return (0);
}

static int	check_nb_elem(int nb_player, int nb_exit, int nb_collectible)
{
	if (nb_player != 1)
		return (ERROR_MAP_FORMAT);
	if (nb_exit != 1)
		return (ERROR_MAP_FORMAT);
	if (nb_collectible == 0)
		return (ERROR_MAP_FORMAT);
	return (0);
}

static int	check_char(char c, int *nb_player, int *nb_exit, int *nb_collec)
{
	if (c == 'P')
		(*nb_player)++;
	else if (c == 'E')
		(*nb_exit)++;
	else if (c == 'C')
		(*nb_collec)++;
	else if (c == '1')
		;
	else if (c == '0')
		;
	else
		return (ERROR_MAP_FORMAT);
	return (0);
}
