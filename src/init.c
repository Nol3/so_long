/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:18:38 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/06 05:55:40 by alcarden         ###   ########.fr       */
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
	elements.map.width = 0;
	elements.map.heigh = 0;
	elements.map.full_map = 0;
	elements.game.elements = 0;
	elements.player_pos_x = 0;
	elements.player_pos_y = 0;
	elements.columns = 0;
	elements.steps = 0;
	return (elements);
}
