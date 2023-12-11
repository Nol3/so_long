/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:38:03 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 20:57:44 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_extension(const char *file_name)
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

int		ft_check_map(char *map)
{
	int	i;
	int	coll;
	int	exit;
	int	player;

	i = 0;
	coll = 0;
	exit = 0;
	player = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			coll++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			player++;
		i++;
	}
	if ((coll < 1 || exit < 1 || player != 1 ) && ft_check_min_items(map) == 0)
		perror("Error\nInvalid map\n");
		return (0);

	return (1);
}

int	ft_check_min_items(char *map)
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
		return (0);
	return (1);
}