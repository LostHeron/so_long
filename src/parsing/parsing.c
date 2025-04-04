/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:07:53 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 16:31:50 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_io.h"
#include "ft_vectors.h"
#include "printing.h"
#include "parsing.h"
#include <fcntl.h>
#include <unistd.h>

static void	my_free(t_vector *ptr_vec);
static void	open_file(int *ptr_fd, char *filename);

int	parsing(char *filename, t_data *ptr_data)
{
	int		fd;
	int		ret;

	open_file(&fd, filename);
	ret = ft_vector_init(&ptr_data->map, 5, sizeof(char *), &my_free);
	if (ret != 0)
	{
		close(fd);
		return (print_error(ret));
	}
	read_map(fd, ptr_data);
	close(fd);
	check_map(ptr_data);
	return (0);
}

static void	open_file(int *ptr_fd, char *filename)
{
	*ptr_fd = open(filename, O_RDONLY);
	if (*ptr_fd == -1)
	{
		print_error(0);
		ft_printf_fd(2, "could not open file : %s\n", filename);
		exit(1);
	}
}

static void	my_free(t_vector *ptr_vec)
{
	size_t	i;

	i = 0;
	while (i < ptr_vec->size)
	{
		free(((char **)ptr_vec->data)[i]);
	}
}
