/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/14 20:55:52 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_read_map(char *file, char **full_map, char **map_cpy)
{
	int		fd;
	char	*temp;
	char	*big_str;
	char	*str;

	fd = open(file, O_RDONLY);
	big_str = malloc(sizeof(char) * 2);
	if (fd == -1)
		perror("File error or empty");
	str = get_next_line(fd);
	if (!str)
		perror("Empty file");
	while (str != NULL && str[0] != '\0')
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
	full_map = ft_split(big_str, '\n');
	map_cpy = ft_split(big_str, '\n');
}


t_element	ft_get_height_width(t_element elements, char **map_load)
{
	int	i;
	int	j;

	i = 0;
	while (map_load[i])
	{
		j = 0;
		while (map_load[i][j])
			j++;
		i++;
	}
	elements.height = i;
	elements.width = j;
	return (elements);
}

void	ft_gen_map(mlx_t *mlx, t_element *element)
{
	int	i;
	int	j;

	i = 0;
	while (element->full_map[i])
	{
		j = 0;
		while (element->full_map[i][j])
		{
			if (element->full_map[i][j] == '1')
				ft_wall(i, j, element);
			else if (element->full_map[i][j] == '0')
				ft_floor(i, j, element);
			else if (element->full_map[i][j] == 'C')
				ft_collectible(i, j, element);
			else if (element.full_map[i][j] == 'E')
				ft_exit(i, j, element);
			else if (element->full_map[i][j] == 'P')
				ft_valere(i, j, element);
			j++;
		}
		i++;
	}
}

// t_element	ft_gen_map_enemy(t_element element)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (element.full_map[i])
// 	{
// 		j = 0;
// 		while (element.full_map[i][j])
// 		{
// 			if (element.full_map[i][j] == '1')
// 				mlx_image_to_window(element.mlx, element.wall, j * 64, i * 64);
// 			else if (element.full_map[i][j] == '0')
// 				mlx_image_to_window(element.mlx, element.floor, j * 64, i * 64);
// 			else if (element.full_map[i][j] == 'C')
// 				ft_collectible(i, j, element);
// 			else if (element.full_map[i][j] == 'E')
// 				ft_exit(i, j, element);
// 			else if (element.full_map[i][j] == 'B')
// 				ft_enemy(i, j, element);
// 			j++;
// 		}
// 		i++;
// 	}
// 	{
// 		element = ft_gen_player(element);
// 		return (element);
// 	}
// }

// t_element	*ft_gen_player(t_element *element)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (element->full_map[i])
// 	{
// 		j = 0;
// 		while (element->full_map[i][j])
// 		{
// 			if (element->full_map[i][j] == 'P')
// 			{
// 				*element = ft_valere(i, j, element);
// 				element->player_pos_x = j;
// 				element->player_pos_y = i;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (element);
// }
