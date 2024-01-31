/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:41:43 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/31 12:51:05 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_create_window(t_element *element)
{
	element = ft_gen_map(element->mlx, element);
	mlx_key_hook(element->mlx, (mlx_keyfunc)ft_movement, element);
	mlx_close_hook(element->mlx, ft_close_window, element);
	mlx_loop_hook(element->mlx, ft_valere_idle, element);
	mlx_loop(element->mlx);
	mlx_terminate(element->mlx);
	ft_free_game(element);
	return (EXIT_SUCCESS);
}

void	ft_close_window(void *param)
{
	t_element	*element;

	element = (t_element *)param;
	free(element->chest);
	ft_free_full_map(element);
	mlx_close_window(element->mlx);
}

mlx_image_t	*ft_put_steps(t_element *element)
{
	mlx_image_t			*phrase;
	mlx_image_t			*steps;
	char				*str;
	static int			first = 0;
	mlx_image_t			*old_steps;

	steps = NULL;
	old_steps = NULL;
	old_steps = steps;
	str = ft_itoa(element->steps);
	if (first < 2147483647)
	{
		phrase = mlx_put_string(element->mlx, "steps: ", 0, 0);
		mlx_image_to_window(element->mlx, phrase, 0, 0);
		steps = mlx_put_string(element->mlx, str, 64, 0);
		mlx_image_to_window(element->mlx, steps, 64, 0);
		first++;
	}
	if (old_steps)
		mlx_delete_image(element->mlx, old_steps);
	free(str);
	return (steps);
}
