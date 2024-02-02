/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:17:32 by alcarden          #+#    #+#             */
/*   Updated: 2024/02/02 18:33:08 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/* */
/* Free memory from images and close */

void	ft_free_game(t_element *element)
{
	if (element->wall != NULL)
		mlx_delete_image(element->mlx, element->wall);
	if (element->floor != NULL)
		mlx_delete_image(element->mlx, element->floor);
	if (element->chest != NULL)
		mlx_delete_image(element->mlx, element->chest);
	if (element->player != NULL)
		mlx_delete_image(element->mlx, element->player);
	if (element->exit != NULL)
		mlx_delete_image(element->mlx, element->exit);
	if (element->enemy != NULL)
		mlx_delete_image(element->mlx, element->enemy);
	if (element->valere1 != NULL)
		mlx_delete_image(element->mlx, element->valere1);
	if (element->valere2 != NULL)
		mlx_delete_image(element->mlx, element->valere2);
	if (element->valere3 != NULL)
		mlx_delete_image(element->mlx, element->valere3);
	free(element->full_map);
	free(element->map_cpy);
	if (element->mlx != NULL)
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
