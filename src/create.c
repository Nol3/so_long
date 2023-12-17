/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/17 16:33:37 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element element, char *file_read)
{
	t_element	*ptr;
	int			tester;

	ptr = &element;
	tester = 0;
	element = ft_init_window(element);
	element = ft_get_height_width(element, file_read);
	element = ft_gen_map(element);
	tester = ft_check_if_reachable(element, element.player_pos_x, element.player_pos_y, &tester);
	// if (tester != 1 || element.columns_counter != element.max_columns)
	// {
	// 	ft_printf("Error:\n El mapa no tiene solución\n");
	// 	ft_free(element.map->full_map);
	// 	exit(1);
	// }
	element.columns = 0;
	element.map->full_map = ft_free(element.map->full_map);
	element.map->full_map = ft_create_map(file_read, element.map->height, element.map->width);
	free(file_read);
	mlx_close_hook(element.mlx, ft_close_window, ptr);
	mlx_key_hook(element.mlx, ft_movement, ptr);
	//mlx_loop_hook(element.mlx, ft_change_exit, ptr);
	mlx_loop(element.mlx);
	return (EXIT_SUCCESS);
}

t_element 	ft_init_window(t_element element)
{
	element.mlx = mlx_init(element.map->width * 64, element.map->height * 64, "so_long", false);
	if (!element.mlx)
	{
		perror("Error\nmlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	element = ft_load_textures(element);
	return (element);
}

void	ft_close_window(void *element)
{
	t_element	*ptr;

	ptr = element;
	free(ptr->columns);
	ptr->map->full_map = ft_free(ptr->map->full_map);
	mlx_close_window(ptr->mlx);
}