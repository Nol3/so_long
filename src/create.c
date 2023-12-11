/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 21:04:15 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//int	ft_create_window(t_element element, char *file_read);
//arreglos para intentar hacer un make antes de irme.

int	ft_create_window(t_element element)
{
	t_element *value;
	int x;

	value = &element;
	x = 0;
	element = ft_init_window(element);
	exit(EXIT_FAILURE);
}

t_element 	ft_init_window(t_element element)
{
	element.mlx = mlx_init(element.map->width * 64, element.map->height * 64, "so_long", 0);
	if (!element.mlx)
	{
		perror("Error\nmlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	element = ft_load_textures(element);
	return (element);
}