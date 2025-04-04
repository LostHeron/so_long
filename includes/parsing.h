/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:10:54 by jweber            #+#    #+#             */
/*   Updated: 2025/04/04 18:33:21 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"

int		parsing(char *filename, t_data *ptr_data);
int		read_map(int fd, t_data *ptr_data);
int		check_map(t_data *ptr_data);
int		check_map_content(t_data *ptr_data);
int		check_map_solution(t_data *p_data);
void	get_player_position(t_data *ptr_data);

#endif
