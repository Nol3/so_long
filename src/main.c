/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2023/11/22 20:08:46 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_data	game;
	t_map	map;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == 1)
		{
			game.mlx = mlx_init(game.mlx, WIDTH, HEIGHT, "so_long");
			if (!game.mlx)
				ft_error();
			mlx_loop(game.mlx);
		}
		else
			ft_printf("Error\nInvalid file extension\n");
	}
	else
	{
		ft_printf("Error\nInvalid number of arguments\n");
		return (0);
	}
}
