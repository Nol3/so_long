/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 16:08:10 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int32_t	main(int argc, char **argv)
{
	t_element	*element;
	char		*map_read;

	element = malloc(sizeof(t_element));
	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 1)
		{
			element = ft_init_elements(element);
			map_read = ft_read_map(argv[1], element);
			if ((ft_check_map(map_read) == 0 && ft_check_min_items(map_read) == 0))
				return (0);
			element = ft_get_height_width(element, map_read);
			element->mlx = mlx_init(element->width, element->height, "so_long", false);
			ft_load_textures(element);
			element = ft_gen_map(element);
			element->full_map = ft_create_map(map_read,
					element->height, element->width);
			ft_create_window(element, map_read);
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
