/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:54 by alcarden          #+#    #+#             */
/*   Updated: 2023/11/22 20:05:15 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_extension(const char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'b' && file_name[i - 2] == 'e'
		&& file_name[i - 3] == 'r' && file_name[i - 4] == '.')
		return (1);
	return (0);
}

int	check_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (map.matrix[i][j] != '1' && map.matrix[i][j] != '0'
				&& map.matrix[i][j] != 'C' && map.matrix[i][j] != 'E'
				&& map.matrix[i][j] != 'P')
			{
				printf("Error\nInvalid map\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_read_map(char *map)
{
	int		fd;
	int		ret;
	char	*buffer;
	char	**matrix;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nInvalid file\n");
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFF_SIZE);
	if (ret == -1)
	{
		printf("Error\nInvalid file\n");
		return (NULL);
	}
	buffer[ret] = '\0';
	matrix = ft_split(buffer, '\n');
	free(buffer);
	return (matrix);
}
