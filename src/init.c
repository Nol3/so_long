/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:18:38 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/12 17:35:23 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_element	ft_init_elements(t_element elements)
{
	elements.mlx = 0;
	elements.wall = 0;
	elements.floor = 0;
	elements.chest = 0;
	elements.player = 0;
	elements.exit = 0;
	elements.enemy = 0;
	elements.width = 0;
	elements.height = 0;
	elements.full_map = 0;
	elements.map_cpy = 0;
	elements.player_pos_x = 0;
	elements.player_pos_y = 0;
	elements.chest_counter = 0;
	elements.max_chest = 0;
	elements.steps = 0;
	elements.count_player = 0;
	elements.count_exit = 0;
	return (elements);
}
