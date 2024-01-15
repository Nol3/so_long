/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:44:42 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/15 14:20:26 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_verify_win(t_element *element)
{
	int		pl_width;
	int		pl_height;
	int		map_width;
	int		map_height;

	pl_height = 0;
	pl_width = 0;
	map_width = 0;
	ft_player_position(element, &pl_width, &pl_height);
	ft_to_fill(element, pl_width, pl_height);
	while (element->map_cpy[map_width])
	{
		map_height = 0;
		while (element->map_cpy[map_width][map_height])
		{
			if (element->map_cpy[map_width][map_height] == 'C'
				|| element->map_cpy[map_width][map_height] == 'E')
				ft_printf("There is no win");
			map_height++;
		}
		map_width++;
	}
}

/*Para conocer la posición de P*/
void	ft_player_position(t_element *element, int *pl_width, int *pl_height)
{
	int	i;
	int	j;

	i = 0;
	while (element->map_cpy[i])
	{
		j = 0;
		while (element->map_cpy[i][j])
		{
			if (element->map_cpy[i][j] == 'P')
			{
				*pl_width = i;
				*pl_height = j;
			}
			j++;
		}
		i++;
	}
}

/*Para usar Flood_fill de forma recursiva*/
void	ft_to_fill(t_element *element, int player_pos_x, int player_pos_y)
{
	flood_fill(element, player_pos_x, player_pos_y);
}

/* flood fill para ubicar la posible E y si es resoluble*/

void	flood_fill(t_element *element, int player_pos_x, int player_pos_y)
{
	if (player_pos_x < 0 || player_pos_y < 0 || player_pos_x >= element->height
		|| player_pos_y >= element->width
		|| element->map_cpy[player_pos_x][player_pos_y] == '1'
				|| element->map_cpy[player_pos_x][player_pos_y] == 'X')
		return ;
	if (((element->map_cpy[player_pos_x + 1][player_pos_y] == 'E')
		|| (element->map_cpy[player_pos_x - 1][player_pos_y] == 'E'))
		&& ((element->map_cpy[player_pos_x][player_pos_y + 1] == '1')
			|| (element->map_cpy[player_pos_x][player_pos_y - 1] == '1')))
		return ;
	if (((element->map_cpy[player_pos_x][player_pos_y + 1] == 'E')
		|| (element->map_cpy[player_pos_x][player_pos_y - 1] == 'E'))
		&& ((element->map_cpy[player_pos_x + 1][player_pos_y] == '1')
		|| (element->map_cpy[player_pos_x - 1][player_pos_y] == '1')))
		return ;
	if (element->map_cpy[player_pos_x][player_pos_y] == 'E' ||
		element->map_cpy[player_pos_x][player_pos_y] == 'C')
		element->map_cpy[player_pos_x][player_pos_y] = '0';
	element->map_cpy[player_pos_x][player_pos_y] = 'X';
	flood_fill(element, player_pos_x - 1, player_pos_y);
	flood_fill(element, player_pos_x + 1, player_pos_y);
	flood_fill(element, player_pos_x, player_pos_y - 1);
	flood_fill(element, player_pos_x, player_pos_y + 1);
}
