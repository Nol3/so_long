/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:18:38 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 19:48:29 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_element	ft_init_elements(t_element elements)
{
	elements.mlx = 0;
	elements.wall = 0;
	elements.floor = 0;
	elements.collect = 0;
	elements.player = 0;
	elements.exit = 0;
	elements.enemy = 0;
	elements.map->width = 0;
	elements.map->height = 0;
	elements.map->full_map = 0;
	elements.player_pos_x = 0;
	elements.player_pos_y = 0;
	elements.chest_counter = 0;
	elements.columns = 0;
	elements.max_columns = 0;
	elements.steps = 0;
	return (elements);
}
