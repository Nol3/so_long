/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:24:09 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/14 17:57:06 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_movement(mlx_key_data_t paramkey, t_element *element)
{
	if ((paramkey.key == MLX_KEY_W || paramkey.key == MLX_KEY_UP)
		&& paramkey.action == MLX_PRESS)
		ft_movement_up(element);
	if ((paramkey.key == MLX_KEY_S || paramkey.key == MLX_KEY_DOWN)
		&& paramkey.action == MLX_PRESS)
		ft_movement_down(element);
	if ((paramkey.key == MLX_KEY_A || paramkey.key == MLX_KEY_LEFT)
		&& paramkey.action == MLX_PRESS)
		ft_movement_left(element);
	if ((paramkey.key == MLX_KEY_D || paramkey.key == MLX_KEY_RIGHT)
		&& paramkey.action == MLX_PRESS)
		ft_movement_right(element);
	if ((paramkey.key == MLX_KEY_ESCAPE || paramkey.key == MLX_KEY_Q)
		&& paramkey.action == MLX_PRESS)
		ft_free_game(element);
}

/*Funtion to move player up, count collectibles and way to win*/
void	ft_movement_up(t_element *element)
{
	if (element->full_map[element->player_pos_x - 1][element->player_pos_y] != '1'
		&& (element->full_map[element->player_pos_x - 1][element->player_pos_y] != 'E'
		|| element->chest_counter == 0))
	{
		element->full_map[element->player_pos_x][element->player_pos_y] = '0';
		if (element->full_map[element->player_pos_x - 1][element->player_pos_y] == 'C')
			element->chest_counter--;
		if (element->full_map[element->player_pos_x - 1][element->player_pos_y] == 'E'
			&& element->chest_counter == 0)
			ft_exit_game(element);
		else
		{
			element->full_map[element->player_pos_x - 1][element->player_pos_y] = 'P';
			ft_gen_map(element->mlx, element);
			element->steps++;
			ft_printf("\nMoves: %d", element->steps);
		}
	}
}

/*Funtion to move player down, count collectibles and way to win*/
void	ft_movement_down(t_element *element)
{
	if (element->full_map[element->player_pos_x + 1][element->player_pos_y] != '1'
		&& (element->full_map[element->player_pos_x + 1][element->player_pos_y] != 'E'
		|| element->chest_counter == 0))
	{
		element->full_map[element->player_pos_x][element->player_pos_y] = '0';
		if (element->full_map[element->player_pos_x + 1][element->player_pos_y] == 'C')
			element->chest_counter--;
		if (element->full_map[element->player_pos_x + 1][element->player_pos_y] == 'E'
			&& element->chest_counter == 0)
			ft_exit_game(element);
		else
		{
			element->full_map[element->player_pos_x + 1][element->player_pos_y] = 'P';
			ft_gen_map(element->mlx, element);
			element->steps++;
			ft_printf("\nMoves: %d", element->steps);
		}
	}
}

/*Funtion to move player left, count collectibles and way to win*/
void	ft_movement_left(t_element *element)
{
	if (element->full_map[element->player_pos_x][element->player_pos_y - 1] != '1'
		&& (element->full_map[element->player_pos_x][element->player_pos_y - 1] != 'E'
		|| element->chest_counter == 0))
	{
		element->full_map[element->player_pos_x][element->player_pos_y] = '0';
		if (element->full_map[element->player_pos_x][element->player_pos_y - 1] == 'C')
			element->chest_counter--;
		if (element->full_map[element->player_pos_x][element->player_pos_y - 1] == 'E'
			&& element->chest_counter == 0)
			ft_exit_game(element);
		else
		{
			element->full_map[element->player_pos_x][element->player_pos_y - 1] = 'P';
			ft_gen_map(element->mlx, element);
			element->steps++;
			ft_printf("\nMoves: %d", element->steps);
		}
	}
}

/*Funtion to move player right, count collectibles and way to win*/
void	ft_movement_right(t_element *element)
{
	if (element->full_map[element->player_pos_x][element->player_pos_y + 1] != '1'
		&& (element->full_map[element->player_pos_x][element->player_pos_y + 1] != 'E'
		|| element->chest_counter == 0))
	{
		element->full_map[element->player_pos_x][element->player_pos_y] = '0';
		if (element->full_map[element->player_pos_x][element->player_pos_y + 1] == 'C')
			element->chest_counter--;
		if (element->full_map[element->player_pos_x][element->player_pos_y + 1] == 'E'
			&& element->chest_counter == 0)
			ft_exit_game(element);
		else
		{
			element->full_map[element->player_pos_x][element->player_pos_y + 1] = 'P';
			ft_gen_map(element->mlx, element);
			element->steps++;
			ft_printf("\nMoves: %d", element->steps);
		}
	}
}
