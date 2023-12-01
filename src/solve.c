/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:44:42 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/01 13:46:03 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Flood fill algorithm

void	ft_check_if_reachable(char **reachmap, int y, int x, t_map map)
{
	if (y < 0 || y >= map.height || x < 0 || x >= map.width)
	{
		return ;
	}
	if (reachmap[y][x] == '1' || reachmap[y][x] == '2')
	{
		return ;
	}
	reachmap[y][x] = '2';
	ft_check_if_reachable(reachmap, y - 1, x, map);
	ft_check_if_reachable(reachmap, y + 1, x, map);
	ft_check_if_reachable(reachmap, y, x - 1, map);
	ft_check_if_reachable(reachmap, y, x + 1, map);
}

