/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:33:32 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/11 21:00:59 by alcarden         ###   ########.fr       */
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
# define WIDTH 256
# define HEIGHT 256


typedef struct s_map
{
	int		width;
	int		height;
	char	**full_map;
}	t_map;

typedef struct s_element
{
	mlx_t		*mlx;
	mlx_image_t	*player;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collect;
	mlx_image_t	*enemy;
	mlx_image_t	**columns;
	int			player_pos_x;
	int			player_pos_y;
	int			max_columns;
	int			steps;
	t_map		*map;
}	t_element;

//create.c
int			ft_create_window(t_element element);
t_element 	ft_init_window(t_element element);

//init.c
t_element	ft_init_elements(t_element elements);

//prefab.c
void		ft_get_wall_img(t_element *mlx);
void		ft_get_floor_img(t_element *mlx);
void		ft_get_chest_img(t_element *mlx);
void		ft_get_player_img(t_element *mlx);
void		ft_get_exit_img(t_element *mlx);

//map_check.c
int			ft_check_extension(const char *file_name);
int			ft_check_map(char *map);
int			ft_check_min_items(char *map);

//map_load.c
char		*ft_read_map(char *str);
char		**ft_create_map(char *map_load, int height, int width);
t_element	ft_get_height_width(t_element elements, char *map_load);

//outs.c
char		**ft_free(char **map);

//png_to_textures.c
t_element	ft_load_textures(t_element element);
t_element	ft_alloc_columns(t_element element);
t_element	ft_get_columns(t_element element, int height, int width);

//solve.c
void		ft_check_if_reachable(char **reachmap, int y, int x, t_map map);

//textures_to_window.c
t_element	ft_valere(int height, int width, t_element element);
void		ft_collectible(int height, int width, t_element element);
t_element	ft_exit(int height, int width, t_element element);
t_element	ft_enemy(int height, int width, t_element element);

//valere_move.c
//void		ft_movement(mlx_key_data_t keydata, void *data);

#endif