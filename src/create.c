/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/14 22:27:38 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element *element)
{
	ft_gen_map(element);
	mlx_key_hook(element->mlx, (mlx_keyfunc)ft_movement, element);
	mlx_close_hook(element->mlx, ft_close_window, element);
	//ft_printf("element.player.count = %d\n", element->player->count);
	mlx_loop(element->mlx);
	mlx_terminate(element->mlx);
	ft_free_game(element);
	return (EXIT_SUCCESS);
}

void	ft_close_window(void *element)
{
	free(element->chest);
	ft_free_full_map(ptr);
	mlx_close_window(ptr->mlx);
}
