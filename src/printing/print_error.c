/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:19:46 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 16:18:20 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "so_long.h"

static void	print_error_malloc(void);
static void	print_error_read(void);
static void	print_error_map_format(void);

int	print_error(int ret)
{
	ft_printf_fd(2, "Error\n");
	if (ret == 0)
		return (ret);
	if (ret == ERROR_READ)
		print_error_read();
	if (ret == ERROR_MALLOC)
		print_error_malloc();
	if (ret == ERROR_MAP_FORMAT)
		print_error_map_format();
	return (ret);
}

static void	print_error_malloc(void)
{
	ft_printf_fd(2, "Memory allocation error\n");
}

static void	print_error_read(void)
{
	ft_printf_fd(2, "read error\n");
}

static void	print_error_map_format(void)
{
	ft_printf_fd(2, "Map format error\n");
}
