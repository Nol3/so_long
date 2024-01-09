/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_and_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:11:47 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/09 19:26:19 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*ft_wall(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->wall,
		width * 64, height * 64);
	return (element);
}

void	*ft_floor(int height, int width, t_element *element)
{
	mlx_image_to_window(element->mlx, element->floor,
		width * 64, height * 64);
	return (element);
}
