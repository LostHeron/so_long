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
static void	my_free(char **map, int nb);
int			flood_fill(char **map, t_data *p_data, size_t x, size_t y);
int			check_after_flood(char **map, t_data *p_data);

int	check_map_solution(t_data *p_data)
{
	char	**map_copy;
	int		ret;

	map_copy = copy_map(p_data->map.data, p_data->nb_lines, p_data->nb_cols);
	if (map_copy == NULL)
		return (ERROR_MALLOC);
	flood_fill(map_copy, p_data, p_data->player.x, p_data->player.y);
	ret = check_after_flood(map_copy, p_data);
	my_free(map_copy, p_data->nb_lines);
	if (ret != 0)
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
	return (new_map);
}

int	flood_fill(char **map, t_data *p_data, size_t x, size_t y)
{
	if (map[x][y] == 'E')
		map[x][y] = 'e';
	if (map[x][y] == 'P' || map[x][y] == 'C' || map[x][y] == '0')
	{
		map[x][y] = 'X';
		if (y < p_data->nb_cols - 1)
			flood_fill(map, p_data, x, y + 1);
		if (y > 0)
			flood_fill(map, p_data, x, y - 1);
		if (x < p_data->nb_lines - 1)
			flood_fill(map, p_data, x + 1, y);
		if (x > 0)
			flood_fill(map, p_data, x - 1, y);
	}
	return (0);
}

int	check_after_flood(char **map, t_data *p_data)
{
	size_t	line_i;
	size_t	col_i;

	line_i = 0;
	while (line_i < p_data->nb_lines)
	{
		col_i = 0;
		while (col_i < p_data->nb_cols)
		{
			if (map[line_i][col_i] == 'C' || map[line_i][col_i] == 'E')
				return (ERROR_MAP_FORMAT);
			col_i++;
		}
		line_i++;
	}
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
