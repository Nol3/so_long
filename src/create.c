/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/17 13:50:41 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element *element)
{
	ft_printf("width: %d, height: %d\n", element->width, element->height);
	element = ft_gen_map(element->mlx, element);
	mlx_key_hook(element->mlx, (mlx_keyfunc)ft_movement, element);
	mlx_close_hook(element->mlx, ft_close_window, element);
	mlx_loop(element->mlx);
	mlx_terminate(element->mlx);
	ft_free_game(element);
	return (EXIT_SUCCESS);
}

void	ft_close_window(void *param)
{
	t_element	*element;

	element = (t_element *)param;
	free(element->chest);
	ft_free_full_map(element);
	mlx_close_window(element->mlx);
}
