/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:24:58 by jweber            #+#    #+#             */
/*   Updated: 2025/04/03 11:26:25 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include "ft_vectors.h"
#include <stdlib.h>

int	free_data(t_data *ptr_data, int ret)
{
	ft_vector_free(&ptr_data->map);
	if (ptr_data->ptr_img_coin != NULL)
		mlx_destroy_image(ptr_data->ptr_mlx, ptr_data->ptr_img_coin);
	return (ret);
}
