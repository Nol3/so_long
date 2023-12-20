/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valere_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:28:30 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 20:58:22 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_movement(mlx_key_data_t keydata, void *data)
{
	t_element	*element_ptr;
	int32_t		*posx;
	int32_t		*posy;

	element_ptr = data;
	posx = &element_ptr->player->instances[0].x;
	posy = &element_ptr->player->instances[0].y;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_next_pos(*posy / 64, *posx / 64, 'w',
				element_ptr->map->full_map) != 1)
			ft_add_step(element_ptr, posx, posy, 'w');
		if (keydata.key == MLX_KEY_A && ft_next_pos(*posy / 64, *posx / 64, 'a',
				element_ptr->map->full_map) != 1)
			ft_add_step(element_ptr, posx, posy, 'a');
		if (keydata.key == MLX_KEY_S && ft_next_pos(*posy / 64, *posx / 64, 's',
				element_ptr->map->full_map) != 1)
			ft_add_step(element_ptr, posx, posy, 's');
		if (keydata.key == MLX_KEY_D && ft_next_pos(*posy / 64, *posx / 64, 'd',
				element_ptr->map->full_map) != 1)
			ft_add_step(element_ptr, posx, posy, 'd');
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_close_window(element_ptr);
		ft_open_exit(*element_ptr);
	}
}

int	ft_next_pos(int32_t height, int32_t width, char key, char **map)
{
	int	res;

	res = 0;
	if (map[height - 1][width] && map[height - 1][width] == '1' && key == 'w')
		res = 1;
	if (map[height][width + 1] && map[height][width + 1] == '1' && key == 'd')
		res = 1;
	if (map[height + 1][width] && map[height + 1][width] == '1' && key == 's')
		res = 1;
	if (map[height][width - 1] && map[height][width - 1] == '1' && key == 'a')
		res = 1;
	return (res);
}

void	ft_add_step(t_element *element_ptr,
		int32_t *posx, int32_t *posy, char key)
{
	if (key == 'w')
		*posy -= 64;
	if (key == 'a')
		*posx -= 64;
	if (key == 's')
		*posy += 64;
	if (key == 'd')
		*posx += 64;
	element_ptr->steps++;
	ft_printf("Steps: %d\n", element_ptr->steps);
}
//change sprite for the bonus. an idle animation for the player