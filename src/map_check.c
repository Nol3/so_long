/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:38:03 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/10 19:34:50 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_extension(const char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	if (file_name[i - 1] == 'r' && file_name[i - 2] == 'e'
		&& file_name[i - 3] == 'b' && file_name[i - 4] == '.')
		return (1);
	return (0);
}

int	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if ((map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
					&& map[i][j] != 'E' && map[i][j] != 'P')
				|| (map[i][j] == 'P' && map[i][j + 1] != '\0'))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_check_min_items(char **map)
{
	int	i;
	int	j;
	int	chest_counter;
	int	exit_counter;

	i = 0;
	j = 0;
	chest_counter = 0;
	exit_counter = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				chest_counter++;
			if (map[i][j] == 'E')
				exit_counter++;
			j++;
		}
		j = 0;
		i++;
	}
	if (chest_counter < 1 || exit_counter < 1)
		return (0);
	return (1);
}