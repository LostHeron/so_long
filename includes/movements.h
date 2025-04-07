/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:01:15 by jweber            #+#    #+#             */
/*   Updated: 2025/04/07 19:04:05 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "so_long.h"

void	move_up(t_data *p_data, char **map);
void	move_down(t_data *p_data, char **map);
void	move_right(t_data *p_data, char **map);
void	move_left(t_data *p_data, char **map);

#endif
