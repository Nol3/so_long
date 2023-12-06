/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_to_window.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:02:30 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/06 06:05:45 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_element	ft_valere(int height, int width, t_element element)
{
	mlx_image_to_window(element.mlx, element.floor, width * 64, height * 64);
	mlx_image_to_window(element.mlx, element.character, width * 64, height * 64);
	return (element);
}

void	ft_collectible(int height, int width, t_element element)
{
	static int	i = 0;

	mlx_image_to_window(element.mlx, element.floor, width * 64, height * 64);
	if (i < element.max_colls)
	{
		mlx_image_to_window(element.mlx, element.colls[i], width * 64, height * 64);
		i++;
	}
}