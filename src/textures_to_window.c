/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:02:30 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/10 19:34:13 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_element	ft_valere(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(element->mlx, element->player,
		width * 64, height * 64);
	return (*element);
}

t_element	ft_exit(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(element->mlx, element->exit,
		width * 64, height * 64);
	return (*element);
}

t_element	ft_enemy(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(element->mlx, element->enemy,
		width * 64, height * 64);
	return (*element);
}

t_element	ft_collectible(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(element->mlx, element->chest,
		width * 64, height * 64);
	return (*element);
}

void	ft_open_exit(t_element *element)
{
	if (element->chest_counter == element->max_chest)
	{
		element->exit->enabled = true;
		if (element->full_map[element->player->instances[0].y
				/ 64][element->player->instances[0].x / 64] == 'E')
		{
			ft_printf("¡Ganas!\n");
			ft_close_window(element);
		}
	}
}
