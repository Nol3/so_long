/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_to_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:21 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 20:18:41 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_element	ft_load_textures(t_element element)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/valere.png");
	element.player = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/enemy.png");
	element.enemy = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/floor.png");
	element.floor = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/wall.png");
	element.wall = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/exit.png");
	element.exit = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/chest.png");
	element.collect = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);
	element = ft_alloc_columns(element);
	return (element);
}

t_element	ft_alloc_columns(t_element element)
{
	element.columns = malloc(sizeof(mlx_image_t *) * element.max_columns + 1);
	element.columns[element.max_columns] = 0;
	if (!element.columns)
	{
		perror("Error\nMalloc error\n");
		exit(EXIT_FAILURE);
	}
	return (element);
}

t_element	ft_load_chest(t_element element)
{
	int				i;
	mlx_texture_t	*texture;

	i = 0;
	while (i < element.max_columns)
	{
		texture = mlx_load_png("./textures/column.png");
		element.columns[i] = mlx_texture_to_image(element.mlx, texture);
		mlx_delete_texture(texture);
		i++;
	}
	return (element);
}