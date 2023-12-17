/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:44:42 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/17 16:16:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Flood fill algorithm

int	ft_check_if_reachable(t_element element, int y, int x, int *value)
{
	char state;

	state = element.map->full_map[y][x];
	if (state != '1' && state != 'T')
	{
		if (state == 'E')
			*value = 1;
		if (state == 'C')
			element.columns_counter++;
		element.map->full_map[y][x] = 'T';
		if (x + 1 < element.map->width)
			ft_check_if_reachable(element, x + 1, y, value);
		if (x - 1 >= 0)
			ft_check_if_reachable(element, x - 1, y, value);
		if (y + 1 < element.map->height)
			ft_check_if_reachable(element, x, y + 1, value);
		if (y - 1 >= 0)
			ft_check_if_reachable(element, x, y - 1, value);
	}
	return (*value);
}

