/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/09 18:44:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int32_t	main(int argc, char **argv)
{
	t_element	*element;

	element = malloc(sizeof(t_element));
	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 1)
		{
			*element = ft_init_elements(*element);
			ft_read_map(argv[1], element);
			if ((ft_check_map(element->map_cpy) == 0
					&& ft_check_min_items(element->map_cpy) == 0))
				return (0);
			*element = ft_get_height_width(*element, element->map_cpy);
			element->mlx = mlx_init(element->width, element->height,
					"so_long", false);
			ft_load_textures(*element);
			ft_create_window(*element, element->full_map);
		}
		else
			perror("Error\nInvalid file extension\n");
	}
	else
		perror("Error\nInvalid number of arguments\n");
	return (0);
}
