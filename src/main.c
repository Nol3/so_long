/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2023/11/28 19:55:26 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#define WIDTH 256
#define HEIGHT 256

// int32_t	main(int argc, char **argv)
// {
// 	t_data	game;
// 	t_map	map;

// 	if (argc == 2)
// 	{
// 		if (check_extension(argv[1]) == 1)
// 		{
// 			game.mlx = mlx_init(game.mlx, WIDTH, HEIGHT, "so_long");
// 			if (!game.mlx)
// 				ft_error();
// 			mlx_loop(game.mlx);
// 		}
// 		else
// 			ft_error("Error\nInvalid file extension\n");
// 	}
// 	else
// 	{
// 		ft_error("Error\nInvalid number of arguments\n");
// 		return (0);
// 	}
// }

int32_t	main(void)
{
	// Create a new instance of mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	if (!mlx)
       perror("error: so_long: mlx_init: ");

	// Create a new image
	mlx_image_t* img = mlx_new_image(mlx, 50, 50);
	if (!img)
		perror("error: so_long: mlx_new_image: ");

	// Set every pixel to white
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        perror("error: so_long: mlx_image_to_window: ");

	mlx_loop(mlx);

	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
