/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valere_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:28:30 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 21:00:56 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// void	ft_movement(mlx_key_data_t keydata, void *data)
// {
// 	t_element	*dataptr;
// 	int32_t	*posx;
// 	int32_t	*posy;

// 	dataptr = data;
// 	posx = &dataptr->player->instances[0].x;
// 	posy = &dataptr->player->instances[0].y;
// 	if (keydata.action == MLX_PRESS)
// 	{
// 		if (keydata.key == MLX_KEY_W && ft_next_pos(*posy / 64, *posx / 64, 'w',
// 				dataptr->map.full_map) != 1)
// 			ft_add_step(dataptr, posx, posy, 'w');
// 		if (keydata.key == MLX_KEY_A && ft_next_pos(*posy / 64, *posx / 64, 'a',
// 				dataptr->map.full_map) != 1)
// 			ft_add_step(dataptr, posx, posy, 'a');
// 		if (keydata.key == MLX_KEY_S && ft_next_pos(*posy / 64, *posx / 64, 's',
// 				dataptr->map.full_map) != 1)
// 			ft_add_step(dataptr, posx, posy, 's');
// 		if (keydata.key == MLX_KEY_D && ft_next_pos(*posy / 64, *posx / 64, 'd',
// 				dataptr->map.full_map) != 1)
// 			ft_add_step(dataptr, posx, posy, 'd');
// 		if (keydata.key == MLX_KEY_ESCAPE)
// 			ft_close_window(dataptr);
// 		ft_open_exit(*dataptr);
// 	}
// }