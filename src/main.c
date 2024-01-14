/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/14 22:18:32 by alcarden         ###   ########.fr       */
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
			ft_init_elements(element);
			ft_read_map(argv[1], element);
			ft_get_height_width(element, element->map_cpy);
			ft_validate_map(element);
			ft_verify_map(element->full_map, element);
			element->mlx = mlx_init(element->width, element->height,
					"so_long", false);
			ft_load_textures(element);
			ft_create_window(element);
		}
		else
			perror("Error\nInvalid file extension\n");
	}
	else
		perror("Error\nInvalid number of arguments\n");
	return (0);
}
