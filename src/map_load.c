/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/15 17:11:31 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	ft_read_map(char *file, t_element *element)
// {
// 	int		fd;
// 	char	*temp;
// 	char	*big_str;
// 	char	*str;

// 	fd = open(file, O_RDONLY);
// 	big_str = malloc(sizeof(char) * 2);
// 	if (fd == -1)
// 		perror("File error or empty");
// 	str = get_next_line(fd);
// 	if (!str)
// 		perror("Empty file");
// 	while (str != NULL && str[0] != '\0')
// 	{
// 		temp = ft_strjoin(big_str, str);
// 		free(big_str);
// 		big_str = temp;
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	free(str);
// 	free(temp);
// 	close(fd);
// 	element->full_map = ft_split(big_str, '\n');
// 	element->map_cpy = ft_split(big_str, '\n');
// }

char	*ft_read_map(char *file)
{
	int		fd;
	int		fsize;
	char	*buff;
	char	*file_read;

	fsize = 0;
	buff = malloc(sizeof(char) * 2);
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) == 1)
		fsize++;
	free(buff);
	if (fsize == 0)
		perror("Empty map");
	close(fd);
	fd = open(file, O_RDONLY);
	file_read = malloc(sizeof(char) * fsize + 1);
	read(fd, file_read, fsize);
	file_read[fsize] = '\0';
	close(fd);
	return (file_read);
}

void	ft_load_map(char *file, t_element *element)
{
	char	*file_read;
	char	**map_load;

	file_read = ft_read_map(file);
	map_load = ft_split(file_read, '\n');
	element->full_map = ft_split(file_read, '\n');
	element->map_cpy = ft_split(file_read, '\n');
	free(file_read);
}

void	ft_get_height_width(t_element *element, char **map_load)
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
	element->height = i;
	element->width = j;
}

t_element	*ft_gen_map(mlx_t *mlx, t_element *element)
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
				ft_wall(mlx, i, j, element);
			else if (element->full_map[i][j] == '0')
				ft_floor(mlx, i, j, element);
			else if (element->full_map[i][j] == 'C')
				ft_collectible(mlx, i, j, element);
			else if (element->full_map[i][j] == 'E')
				ft_exit(mlx, i, j, element);
			else if (element->full_map[i][j] == 'P')
				ft_valere(mlx, i, j, element);
			j++;
		}
		i++;
	}
	//element = ft_gen_player(mlx, element);
	return (element);
}

// t_element	*ft_gen_player(mlx_t *mlx, t_element *element)
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
// 				ft_valere(mlx, i, j, element);
// 				element->player_pos_x = j;
// 				element->player_pos_y = i;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (element);
// }

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

