/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/01 14:07:15 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#define WIDTH 256
#define HEIGHT 256

int32_t	main(int argc, char **argv)
{
	int			i;
	t_element	elements;
	char		*map_read;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == 1)
		{
			elements = ft_init_elements(elements);
			map_read = ft_read_map(argv[1]);
			elements.map = ft_get_map(map_read);
			elements = ft_get_height_width(elements, map_read);
			elements.map->full_map = ft_create_map(map_read, elements.map->height, elements.map->width);
			if (!elements.map)
				perror("Error\nInvalid map\n");
			if (!check_map(elements.map))
				perror("Error\nInvalid map\n");
		}
		else
			perror("Error\nInvalid file extension\n");
	}
	else
	{
		perror("Error\nInvalid number of arguments\n");
		return (0);
	}
}
