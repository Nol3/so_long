/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/10 19:22:11 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element *element)
{
	int		tester;

	tester = 0;
	element = ft_gen_map(element);
	//element->full_map = ft_create_map(element->full_map,
			//element->height, element->width);
	// tester = ft_check_if_reachable(element, element.player_pos_x, element.player_pos_y, &tester);
	// if (tester != 1)
	// {
	// 	ft_printf("Error:\n El mapa no tiene solución\n");
	// 	exit(1);
	// }
	mlx_close_hook(element->mlx, ft_close_window, element);
	mlx_key_hook(element->mlx, ft_movement, element);
	ft_printf("element.player.count = %d\n", element->player->count);
	mlx_loop(element->mlx);
	return (EXIT_SUCCESS);
}

void	ft_close_window(void *element)
{
	t_element	*ptr;

	ptr = element;
	free(ptr->chest);
	ptr->full_map = ft_free(ptr->full_map);
	mlx_close_window(ptr->mlx);
}
