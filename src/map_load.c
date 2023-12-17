/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/17 13:50:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_read_map(char *str)
{
	int		fd;
	char	*buff;
	char	*map;
	int		map_size;

	map_size = 0;
	buff = malloc(sizeof(char) * 2);
	fd = open(str, O_RDONLY);
	while (read(fd, buff, 1) == 1)
		map_size++;
	free(buff);
	close(fd);
	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char) * map_size + 1);
	read(fd, map, map_size);
	map[map_size] = '\0';
	close(fd);
	return (map);
}

char **ft_create_map(char *map_load, int height, int width)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		perror("Error\nCreate map height Malloc error\n");
	while (i < height)
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		if (!map[i])
			perror("Error\nCreate map width Malloc error\n");
		j = 0;
		while (j < width)
		{
			map[i][j] = map_load[i * (width + 1) + j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_element	ft_get_height_width(t_element elements, char *map_load)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = 0;
	width = 0;
	while (map_load[i])
	{
		if (map_load[i] == '\n')
			height++;
		if (height == 0)
			width++;
		i++;
	}
	elements.map->height = height;
	elements.map->width = width;
	return (elements);
}
t_element	ft_gen_map(t_element element)
{
	int i;
	int j;

	i = 0;
	while (element.map->full_map[i])
	{
		j = 0;
		while (element.map->full_map[i][j])
		{
			if (element.map->full_map[i][j] == '1')
				mlx_image_to_window(element.mlx, element.wall, j * 64, i * 64);
			else if (element.map->full_map[i][j] == '0')
				mlx_image_to_window(element.mlx, element.floor, j * 64, i * 64);
			else if (element.map->full_map[i][j] == 'C')
				mlx_image_to_window(element.mlx, element.collect, j * 64, i * 64);
			else if (element.map->full_map[i][j] == 'E')
				mlx_image_to_window(element.mlx, element.exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	{
		element = ft_gen_player(element);
		return (element);
	}
}

t_element	ft_gen_player(t_element element)
{
	int	i;
	int	j;

	i = 0;
	while (element.map->full_map[i])
	{
		j = 0;
		while (element.map->full_map[i][j])
		{
			if (element.map->full_map[i][j] == 'P')
			{
				element = ft_valere(i, j, element);
				element.player_pos_x = j;
				element.player_pos_y = i;
			}
			j++;
		}
		i++;
	}
	return (element);
}
