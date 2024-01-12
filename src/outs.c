/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:17:32 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/12 17:15:53 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* */
/* Free memory from images and close */

void	ft_free_game(t_element *element)
{
	mlx_delete_image(element->mlx, element->floor);
	mlx_delete_image(element->mlx, element->wall);
	mlx_delete_image(element->mlx, element->chest);
	mlx_delete_image(element->mlx, element->player);
	mlx_delete_image(element->mlx, element->exit);
	free(element->full_map);
	mlx_close_window(element->mlx);
	exit(EXIT_SUCCESS);
}

/* */
/* Free memory from all full_map */

void	ft_free_full_map(t_element *element)
{
	int	i;

	i = 0;
	while (i < element->width)
	{
		free(element->full_map[i]);
		i++;
	}
	free(element->full_map);
	element->full_map = NULL;
}