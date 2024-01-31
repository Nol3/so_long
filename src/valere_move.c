/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valere_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:44:55 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/31 12:51:29 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_valere_idle(t_element *element)
{
    static int timer = 0;

    timer++;
	ft_player_position_animation(element);
    if (timer % 10 == 0) // Cambia la imagen cada 50 ciclos
    {
        // Alterna entre las imágenes
        if (element->valere == element->valere1)
            element->valere = element->valere2;
        else if (element->valere == element->valere2)
            element->valere = element->valere3;
        else
            element->valere = element->valere1;
		mlx_image_to_window(element->mlx, element->valere,
            element->move_y * 64, element->move_x * 64);
    }
	return (0);
}

void	ft_valere_load(t_element *element)
{
	mlx_texture_t	*valere_idle;

	valere_idle = mlx_load_png("./textures/valere_idle/idle_1.png");
	element->valere1 = mlx_texture_to_image(element->mlx, valere_idle);
	mlx_delete_texture(valere_idle);

	valere_idle = mlx_load_png("./textures/valere_idle/idle_2.png");
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

void	ft_player_position_animation(t_element *element)
{
	int	i;
	int	j;

	i = 0;
	while (element->map_cpy[i])
	{
		j = 0;
		while (element->map_cpy[i][j])
		{
			if (element->map_cpy[i][j] == 'P')
			{
				element->player_pos_x = j;
				element->player_pos_y = i;
			}
			j++;
		}
		i++;
	}
}
