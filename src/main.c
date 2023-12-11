/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:32:45 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 17:33:56 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int32_t	main(int argc, char **argv)
{
	//int			i;
	t_element	element;
	char		*map_read;

	if (argc == 2)
	{
		if (ft_check_extension(argv[1]) == 1)
		{
			element = ft_init_elements(element);
			map_read = ft_read_map(argv[1]);
			element.map = ft_check_map(map_read);
			element = ft_get_height_width(element, map_read);
			element.map->full_map = ft_create_map(map_read, element.map->height, element.map->width);
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
