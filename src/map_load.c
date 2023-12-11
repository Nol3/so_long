/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 17:05:20 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	ft_read_map(char *str)
{
	int		fd;
	char	*buff;
	char	*map;
	int		map_size;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("Error\nInvalid file\n");
	buff = malloc(sizeof(char) * 2);
	if (!buff)
		perror("Error\nMalloc error\n");
	while ( read(fd, buff, 1) == 1)
	{
		map_size++;
	}
	free(buff);
	fd = open(str, O_RDONLY);
	map = malloc(sizeof(char) * (map_size + 1));
	if (!map)
		perror("Error\nMalloc error\n");
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
	map[i] = '\0';
	return (map);
}

t_element	ft_get_height_width(t_element elements, char *map_load)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	height = 0;
	width = 0;
	while (map_load[i])
	{
		j = 0;
		while (map_load[i] != '\n')
		{
			i++;
			j++;
		}
		if (j > width)
			width = j;
		height++;
		i++;
	}
	elements.map->height = height;
	elements.map->width = width;
	return (elements);
}
