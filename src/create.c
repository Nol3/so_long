/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/09 18:59:50 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element element, char *file_read)
{
	t_element	*ptr;
	int			tester;

	ptr = &element;
	tester = 0;
	*ptr = ft_gen_map(*ptr);
	ptr->full_map = ft_create_map(ptr->full_map,
			ptr->height, ptr->width);
	// tester = ft_check_if_reachable(element, element.player_pos_x, element.player_pos_y, &tester);
	// if (tester != 1)
	// {
	// 	ft_printf("Error:\n El mapa no tiene solución\n");
	// 	exit(1);
	// }
	mlx_close_hook(element.mlx, ft_close_window, ptr);
	mlx_key_hook(element.mlx, ft_movement, ptr);
	ft_printf("element.player.count = %d\n", element.player->count);
	mlx_loop(element.mlx);
	return (EXIT_SUCCESS);
}

/* t_element	ft_init_window(t_element element)
{
	element.mlx = mlx_init(element.map->width * 64, element.map->height * 64, "So_long", false);
	if (!element.mlx)
	{
		perror("Error\nmlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	element = ft_load_textures(element);
	return (element);
} */

void	ft_close_window(void *element)
{
	t_element	*ptr;

	ptr = element;
	free(ptr->chest);
	ptr->full_map = ft_free(ptr->full_map);
	mlx_close_window(ptr->mlx);
}
