/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:17:00 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:34:47 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, int nb_lines, int nb_cols);
static int	fill_x_map_copy(char **map, int nb_lines, int nb_cols);
static void	my_free(char **map, int nb);

int	check_map_solution(t_data *p_data)
{
	char	**map_copy;

	map_copy = copy_map(p_data->map.data, p_data->nb_lines, p_data->nb_cols);
	if (map_copy == NULL)
		return (ERROR_MALLOC);
	if (fill_x_map_copy(map_copy, p_data->nb_cols, p_data->nb_lines) != 0)
		return (ERROR_MAP_FORMAT);
	return (0);
}

static char	**copy_map(char **map, int nb_lines, int nb_cols)
{
	int		line_i;
	int		col_i;
	char	**new_map;

	new_map = malloc(nb_lines * sizeof(char *));
	if (new_map == NULL)
		return (NULL);
	line_i = 0;
	while (line_i < nb_lines)
	{
		new_map[line_i] = malloc(nb_cols * sizeof(char));
		if (new_map[line_i] == NULL)
		{
			my_free(new_map, line_i);
		}
		col_i = 0;
		while (col_i < nb_cols)
		{
			new_map[line_i][col_i] = map[line_i][col_i];
			col_i ++;
		}
		line_i++;
	}
	return (map);
}

static int	fill_x_map_copy(char **map, int nb_lines, int nb_cols, t_pos player)
{
	fill_recursively(map, player.x, player.y);
	return (0);
}

static void	my_free(char **map, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
