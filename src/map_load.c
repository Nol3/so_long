/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 18:15:40 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_read_map(char *file)
{
	int		fd;
	int		fsize;
	char	*buff;
	char	*file_read;

	fsize = 0;
	ft_check_extension(file);
	buff = malloc(sizeof(char) * 2);
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) == 1)
		fsize++;
	free(buff);
	if (fsize == 0)
		perror("Error\nEmpty file\n");
	close(fd);
	fd = open(file, O_RDONLY);
	file_read = malloc(sizeof(char) * fsize + 1);
	read(fd, file_read, fsize);
	file_read[fsize] = '\0';
	close(fd);
	return (file_read);
}

char	**ft_create_map(char *map_load, int height, int width)
{
	int		i;
	int		j;
	int		k;
	char	**map;

	i = 0;
	k = 0;
	map = malloc(sizeof(char *) * (height + 1));
	while (i < height && map_load[k] != '\0')
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (width + 1));
		while (j < width && map_load[k] != '\n')
		{
			map[i][j] = map_load[k];
			j++;
			k++;
		}
		k++;
		map[i][j] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

t_element	ft_get_height_width(t_element elements, char *map_load)
{
    int	i;
    int	height;
    int	width;

    if (!elements.map)
    {
        perror("Error\nelements.map is NULL\n");
        return elements;
    }

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
    elements.map->height = height + 1;
    elements.map->width = width;
    return (elements);
}

t_element	ft_gen_map(t_element element)
{
	int	i;
	int	j;

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
				ft_collectible(i, j, element);
			else if (element.map->full_map[i][j] == 'E')
				ft_exit(i, j, element);
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

// char	**ft_create_map(char *map_load, int height, int width)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	**map;

// 	i = 0;
// 	k = 0;
// 	map = malloc(sizeof(char *) * (height + 1));
// 	if (!map)
// 		perror("Error\nCreate map height Malloc error\n");
// 	while (i < height && map_load[k] != '\0')
// 	{
// 		j = 0;
// 		map[i] = malloc(sizeof(char) * (width + 1));
// 		while (j < width && map_load[k] != '\n')
// 		{
// 			map[i][j] = map_load[k];
// 			j++;
// 			k++;
// 		}
// 		k++;
// 		map[i][j] = '\0';
// 		i++;
// 	}
// 	map[i] = 0;
// 	return (map);
// }

// t_element	ft_get_height_width(t_element elements, char *map_load)
// {
// 	int	i;
// 	int	height;
// 	int	width;

// 	i = 0;
// 	height = 0;
// 	width = 0;
// 	while (map_load[i])
// 	{
// 		if (map_load[i] == '\n')
// 			height++;
// 		if (height == 0)
// 			width++;
// 		i++;
// 	}
// 	elements.map->height = height + 1;
// 	elements.map->width = width;
// 	return (elements);
// }