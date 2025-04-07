/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:39:27 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 17:45:01 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "so_long.h"

int	open_sprite(t_data *data);
int	put_sprite(t_data *p_data);
int	get_ptr_exit(t_data *p_data, char *filename);
int	get_ptr_coin(t_data *p_data, char *filename);
int	get_ptr_player(t_data *p_data, char *filename);
int	get_ptr_wall(t_data *p_data, char *filename);
int	get_ptr_ground(t_data *p_data, char *filename);

#endif
