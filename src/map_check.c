/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:38:03 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/01 13:46:07 by alcarden         ###   ########.fr       */
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
			if (map.full_map[i][j] != '1' && map.full_map[i][j] != '0'
				&& map.full_map[i][j] != 'C' && map.full_map[i][j] != 'E'
				&& map.full_map[i][j] != 'P')
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

void	ft_check_min_items(char *map)
{
	int	i;
	int	coll;
	int	exit;

	i = 0;
	coll = 0;
	exit = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			coll++;
		if (map[i] == 'E')
			exit++;
		i++;
	}
	if (coll < 1 || exit < 1)
	{
		ft_error("Error\nInvalid map\n");
	}
}