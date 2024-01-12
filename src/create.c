/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/12 17:24:20 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element *element)
{
	element = ft_gen_map(element);



	mlx_close_hook(element->mlx, ft_close_window, element);
	mlx_key_hook(element->mlx, ft_movement, element);
	//ft_printf("element.player.count = %d\n", element->player->count);
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
