/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_to_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:21 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/17 18:05:34 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_load_textures(t_element *element)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/valere.png");
	element->player = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/enemy.png");
	element->enemy = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/floor.png");
	element->floor = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/wall.png");
	element->wall = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/exit.png");
	element->exit = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/chest.png");
	element->chest = mlx_texture_to_image(element->mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_load_idle(t_element *element)