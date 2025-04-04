/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:46 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 17:32:11 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "printing.h"
#include "ft_io.h"
#include <unistd.h>

int	read_map(int fd, t_data *ptr_data)
{
	char	*line;
	int		err_code;

	line = get_next_line(fd, &err_code);
	if (err_code != 0)
	{
		print_error(err_code);
		close(fd);
		exit (err_code);
	}
	while (line != NULL)
	{
		ft_vector_add_single(&ptr_data->map, &line);
		line = get_next_line(fd, &err_code);
		if (err_code != 0)
		{
			print_error(err_code);
			ft_vector_free(&ptr_data->map);
			close(fd);
			exit (err_code);
		}
	}
	return (0);
}
