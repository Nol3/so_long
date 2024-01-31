/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valere_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:44:55 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/30 21:07:18 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_valere_idle(t_element *element)
{
    static int animation_state = 0;
    static int timer = 0;


    timer++;
    if (timer % 50 == 0) // Cambia la imagen cada 10 ciclos
    {
        animation_state = (animation_state + 1) % 3; // Cicla entre 0, 1 y 2
        if (animation_state == 0)
            element->valere = element->valere1;
        else if (animation_state == 1)
            element->valere = element->valere2;
        else
            element->valere = element->valere3;
		int i, j;
        for (i = 0; element->full_map[i]; i++)
        {
            for (j = 0; element->full_map[i][j]; j++)
            {
                if (element->full_map[i][j] == 'P')
                {
                    // Dibuja la imagen del personaje en la posición correcta
                    mlx_image_to_window(element->mlx, element->player,
                        j * 64, i * 64);
                    return 0;
                }
            }
        }
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
        // Manejar el error, imprimir un mensaje y salir
        perror("Error\nFailed to load textures\n");
        exit(EXIT_FAILURE);
    }
}
