/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:15:42 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:29:04 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_vectors.h"
#include "ft_string.h"
#include "printing.h"
#include "parsing.h"

static int	check_line_len(t_data *ptr_data);
static void	delete_new_line_char(t_data *ptr_data);
static int	check_map_wall(t_data *ptr_data);

int	check_map(t_data *ptr_data)
{
	int	ret;

	delete_new_line_char(ptr_data);
	ret = check_line_len(ptr_data);
	if (ret != 0)
	{
		ft_vector_free(&ptr_data->map);
		exit (print_error(ret));
	}
	ret = check_map_content(ptr_data);
	if (ret != 0)
		return (print_error(ret));
	ret = check_map_wall(ptr_data);
	if (ret != 0)
		return (print_error(ret));
	get_player_position(ptr_data);
	ret = check_map_solution(ptr_data);
	if (ret != 0)
		return (print_error(ret));
	return (0);
}

static void	delete_new_line_char(t_data *ptr_data)
{
	size_t	line_i;
	size_t	char_i;

	line_i = 0;
	while (line_i < ptr_data->map.size)
	{
		char_i = 0;
		while (((char **)ptr_data->map.data)[line_i][char_i])
		{
			if (((char **)ptr_data->map.data)[line_i][char_i] == '\n')
				((char **)ptr_data->map.data)[line_i][char_i] = '\0';
			char_i++;
		}
		line_i++;
	}
}

static int	check_line_len(t_data *ptr_data)
{
	size_t	line_len;
	size_t	line_i;

	line_len = ft_strlen(((char **)ptr_data->map.data)[0]);
	line_i = 1;
	while (line_i < ptr_data->map.size)
	{
		if (ft_strlen(((char **)ptr_data->map.data)[line_i]) != line_len)
		{
			return (ERROR_MAP_FORMAT);
		}
		line_i++;
	}
	ptr_data->nb_cols = line_len;
	ptr_data->nb_lines = ptr_data->map.size;
	return (0);
}

static int	check_map_wall(t_data *ptr_data)
{
	size_t	line_i;
	size_t	col_i;

	line_i = 0;
	while (line_i < ptr_data->nb_lines)
	{
		col_i = 0;
		while (col_i < ptr_data->nb_cols)
		{
			if (line_i == 0 || line_i == ptr_data->nb_cols -1
				|| col_i == 0 || col_i == ptr_data->nb_cols -1)
				if (((char **)ptr_data->map.data)[line_i][col_i] != '1')
					return (ERROR_MAP_FORMAT);
			col_i++;
		}
		line_i++;
	}
	return (0);
}
