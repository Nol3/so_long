/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:02:30 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/17 17:33:46 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_valere(mlx_t *mlx, int height, int width, t_element *element)
{
	mlx_image_to_window(mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(mlx, element->player,
		width * 64, height * 64);
	element->move_x = height;
	element->move_y = width;
}

void	ft_exit(mlx_t *mlx, int height, int width, t_element *element)
{
	mlx_image_to_window(mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(mlx, element->exit,
		width * 64, height * 64);
}

void	ft_enemy(mlx_t *mlx, int height, int width, t_element *element)
{
	mlx_image_to_window(mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(mlx, element->enemy,
		width * 64, height * 64);
}

void	ft_collectible(mlx_t *mlx, int height, int width, t_element *element)
{
	mlx_image_to_window(mlx, element->floor,
		width * 64, height * 64);
	mlx_image_to_window(mlx, element->chest,
		width * 64, height * 64);
}

// void	ft_open_exit(t_element *element)
// {
// 	if (element->chest_counter == element->max_chest)
// 	{
// 		element->exit->enabled = true;
// 		if (element->full_map[element->player->instances[0].y
// 				/ 64][element->player->instances[0].x / 64] == 'E')
// 		{
// 			ft_printf("¡Ganas!\n");
// 			ft_close_window(element);
// 		}
// 	}
// }
