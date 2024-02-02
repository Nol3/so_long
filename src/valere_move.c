/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valere_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:44:55 by alcarden          #+#    #+#             */
/*   Updated: 2024/02/02 15:51:39 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_character(t_element *element, int animation_state, int i, int j)
{
	mlx_image_to_window(element->mlx, element->floor,
		j * 64, i * 64);
	if (animation_state == 0)
		element->player = element->valere1;
	else if (animation_state == 1)
		element->player = element->valere2;
	else
		element->player = element->valere3;
	mlx_image_to_window(element->mlx, element->player,
		j * 64, i * 64);
}

void	ft_player_position_animation(t_element *element, int animation_state)
{
	int	i;
	int	j;

	i = 0;
	while (element->full_map[i])
	{
		j = 0;
		while (element->full_map[i][j])
		{
			if (element->full_map[i][j] == 'P')
			{
				draw_character(element, animation_state, i, j);
			}
			j++;
		}
		i++;
	}
}

int	ft_valere_idle(t_element *element)
{
	static int	animation_state = 0;
	static int	timer = 0;

	timer++;
	if (timer % 15 == 0)
	{
		animation_state = (animation_state + 1) % 3;
		ft_player_position_animation(element, animation_state);
	}
	return (0);
}

void	ft_valere_load(t_element *element)
{
	mlx_texture_t	*valere_idle;

	valere_idle = mlx_load_png("./textures/valere_idle/idle_1.png");
	element->valere1 = mlx_texture_to_image(element->mlx, valere_idle);
	mlx_delete_texture(valere_idle);
	valere_idle = mlx_load_png("./textures/valere_idle/idle_4.png");
	element->valere2 = mlx_texture_to_image(element->mlx, valere_idle);
	mlx_delete_texture(valere_idle);
	valere_idle = mlx_load_png("./textures/valere_idle/idle_3.png");
	element->valere3 = mlx_texture_to_image(element->mlx, valere_idle);
	mlx_delete_texture(valere_idle);
	if (!element->valere1 || !element->valere2 || !element->valere3)
	{
		perror("Error\nFailed to load textures\n");
		exit(EXIT_FAILURE);
	}
}
