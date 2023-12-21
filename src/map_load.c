/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 21:08:45 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*ft_read_map(char *file, t_element *element)
{
	int		fd;
	char	*temp;
	char	*big_str;
	char	*str;

	fd = open(file, O_RDONLY);
	big_str = ft_strdup("");
	if (fd == -1)
		print_error("File error or empty");
	str = get_next_line(fd);
	if (!str)
		print_error("Empty file");
	while (str != '\0')
	{
		temp = ft_strjoin(big_str, str);
		free(big_str);
		big_str = temp;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	free(temp);
	close(fd);
	element->full_map = ft_split(file_read, '\n');
	element->map_cpy = ft_split(file_read, '\n');
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

	if (!elements->map)
	{
		perror("Error\nelements->map is NULL\n");
		return (elements);
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
	elements->height = height + 1;
	elements->width = width;
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
			else if (element.map->full_map[i][j] == 'B')
				ft_enemy(i, j, element);
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
