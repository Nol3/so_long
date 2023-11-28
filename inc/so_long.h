/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:33:32 by alcarden          #+#    #+#             */
/*   Updated: 2023/11/28 21:31:10 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../include/inc/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>

# define BUFF_SIZE 10000
# define WIDTH 50
# define HEIGHT 50
// typedef struct t_map
// {
// 	char		**matrix;
// 	int			width;
// 	int			height;
// }				t_map;

// typedef struct s_data
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*character;
// 	mlx_image_t	*collect;
// 	mlx_image_t	*floor;
// 	mlx_image_t	*wall;
// 	mlx_image_t	**colls;
// 	mlx_image_t	*exit;
// 	t_map		map;
// 	int			player_pos_x;
// 	int			player_pos_y;
// 	int			coll_count;
// 	int			max_colls;
// 	int			steps;
// }				t_data;

typedef struct s_element
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collect;
	mlx_image_t	*character;
	mlx_image_t	*exit;
}	t_element;

typedef struct s_map
{
	int		width;
	int		height;
	char	**full_map;
	int		pos[2];
}	t_map;

typedef struct s_game
{
	t_element	*elements;
	t_map		*map;
}	t_game;

void ft_error(void);
int	check_extension(const char *file_name);
int	check_map(t_map map);

//prefab.c
void	ft_get_wall_img(t_element *mlx);
void	ft_get_floor_img(t_element *mlx);
void	ft_get_chest_img(t_element *mlx);
void	ft_get_player_img(t_element *mlx);
void	ft_get_exit_img(t_element *mlx);

//map.c
int		ft_check_extension(const char *file_name);
int		ft_check_map(t_map map);
void	ft_check_if_reachable(char **reachmap, int y, int x, t_map map);
void	ft_check_min_items(char *map);

#endif