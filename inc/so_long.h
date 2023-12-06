/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:33:32 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/06 05:58:13 by alcarden         ###   ########.fr       */
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

typedef struct s_element
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collect;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	**columns;
	t_map		*map;
	t_game		*game;
	int			player_pos_x;
	int			player_pos_y;
	int			max_columns;
	int			steps;
}	t_element;

typedef struct s_map
{
	int		width;
	int		height;
	char	**full_map;
}	t_map;

typedef struct s_game
{
	t_element	*elements;
}	t_game;

//outs.c
char	**ft_free(char **map);

//prefab.c
void	ft_get_wall_img(t_element *mlx);
void	ft_get_floor_img(t_element *mlx);
void	ft_get_chest_img(t_element *mlx);
void	ft_get_player_img(t_element *mlx);
void	ft_get_exit_img(t_element *mlx);

//map_check.c
int		ft_check_extension(const char *file_name);
int		ft_check_map(t_map map);
void	ft_check_min_items(char *map);

//solve.c
void	ft_check_if_reachable(char **reachmap, int y, int x, t_map map);

//map_load.c
char	ft_read_map(char *str);
char **ft_create_map(char *map_load, int height, int width);
t_element	ft_get_height_width(t_element elements, char *map_load);

//init.c
t_element	ft_init_elements(t_element elements);
#endif