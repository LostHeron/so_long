/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:46:05 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:15:58 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_vectors.h"

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_data
{
	t_vector	map;
	size_t		nb_cols;
	size_t		nb_lines;
	t_pos		player;
	t_pos		exit;
	void		*ptr_mlx;
	void		*ptr_win;
	void		*ptr_img_ground;
	void		*ptr_img_wall;
	void		*ptr_img_coin;
	void		*ptr_img_player;
}			t_data;

# define ERROR_READ -1
# define ERROR_MALLOC -3
# define ERROR_OPEN -6
# define ERROR_MAP_FORMAT -7

#endif 
