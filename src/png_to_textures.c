/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_to_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:57:21 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/06 06:07:03 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

t_element	ft_load_textures(t_element element)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/valere.png");
	element.player = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/floor.png");
	element.floor = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	element = ft_alloc_columns(element);
	texture = mlx_load_png("./textures/wall.png");
	element.wall = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	texture = mlx_load_png("./textures/exit.png");
	element.exit = mlx_texture_to_image(element.mlx, texture);
	mlx_delete_texture(texture);

	element = ft_collectible_texture(element);
	return (elements);
}

t_element	ft_alloc_columns(t_element element)
{
	element.columns = malloc(sizeof(mlx_image_t *) * element.max_columns + 1);
	element.columns[element.max_colls] = 0;
	return (element);
}



// void	ft_get_wall_img(t_element *mlx)
// {
// 	mlx_image_t	*wall;

// 	wall = malloc(sizeof(mlx_image_t) * 1);
// 	wall = mlx_load_png("./textures/wall.png");
// 	((t_game *)mlx)->elements->wall = mlx_texture_to_image(mlx, wall);
// 	mlx_resize_image(((t_game *)mlx)->elements->wall, 50, 50);
// 	mlx_delete_image(mlx, wall);
// }

// void	ft_get_floor_img(t_element *mlx)
// {
// 	mlx_image_t	*floor;

// 	floor = malloc(sizeof(mlx_image_t) * 1);
// 	floor = mlx_load_png("./textures/floor.png");
// 	((t_game *)mlx)->elements->floor = mlx_texture_to_image(mlx, floor);
// 	mlx_resize_image(((t_game *)mlx)->elements->floor, 50, 50);
// 	mlx_delete_image(mlx, floor);
// }

// void ft_get_chest_img(t_element *mlx)
// {
// 	mlx_image_t	*collect;

// 	collect = malloc(sizeof(mlx_image_t) * 1);
// 	collect = mlx_load_png("./textures/chest.png");
// 	((t_game *)mlx)->elements->collect = mlx_texture_to_image(mlx, collect);
// 	mlx_resize_image(((t_game *)mlx)->elements->collect, 20, 20);
// 	mlx_delete_image(mlx, collect);
// }

// void ft_get_player_img(t_element *mlx)
// {
// 	mlx_image_t	*player;

// 	player = malloc(sizeof(mlx_image_t) * 1);
// 	player = mlx_load_png("./textures/valere.png");
// 	((t_game *)mlx)->elements->player = mlx_texture_to_image(mlx, player);
// 	mlx_resize_image(((t_game *)mlx)->elements->player, 50, 50);
// 	mlx_delete_image(mlx, player);
// }

// void ft_get_exit_img(t_element *mlx)
// {
// 	mlx_image_t	*exit;

// 	exit = malloc(sizeof(mlx_image_t) * 1);
// 	exit = mlx_load_png("./textures/exit.png");
// 	((t_game *)mlx)->elements->exit = mlx_texture_to_image(mlx, exit);
// 	mlx_resize_image(((t_game *)mlx)->elements->exit, 35, 35);
// 	mlx_delete_image(mlx, exit);
// }

