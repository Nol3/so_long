/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:33:32 by alcarden          #+#    #+#             */
/*   Updated: 2024/01/14 17:51:54 by alcarden         ###   ########.fr       */
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

# define BUFFER_SIZE 512
// # define WIDTH 512
// # define HEIGHT 512

typedef struct s_element
{
	mlx_t			*mlx;
	mlx_image_t		*player;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*exit;
	mlx_image_t		*enemy;
	mlx_image_t		*chest;
	int				player_pos_x;
	int				player_pos_y;
	int				max_chest;
	int				chest_counter;
	int				count_player;
	int				count_exit;
	int				steps;
	int				width;
	int				height;
	char			**full_map;
	char			**map_cpy;
}	t_element;

//create.c
int				ft_create_window(t_element *element);
t_element		ft_init_window(t_element element);
void			ft_close_window(void *element);

//init.c
t_element		ft_init_elements(t_element elements);
void		ft_validate_map(t_game *element);

//prefab.c
void			ft_get_wall_img(t_element *mlx);
void			ft_get_floor_img(t_element *mlx);
void			ft_get_chest_img(t_element *mlx);
void			ft_get_player_img(t_element *mlx);
void			ft_get_exit_img(t_element *mlx);

//map_check.c
int				ft_check_extension(const char *file_name);
int				ft_check_map(char **map);
int				ft_check_min_items(char **map);

//map_load.c
void	ft_read_map(char *file, char **full_map, char **map_cpy);
//char			**ft_create_map(char *map_load, int height, int width);
t_element		ft_get_height_width(t_element elements, char **map_load);

//move2.c


//outs.c
void			ft_free_game(t_element *element);
void			ft_free_full_map(t_element *element);

//png_to_textures.c
t_element		ft_chest_texture(t_element element);
t_element		*ft_alloc_chest(t_element *element);
t_element		*ft_load_textures(t_element *element);
t_element		ft_alloc_columns(t_element element);
t_element		ft_get_columns(t_element element, int height, int width);
void			ft_gen_map(mlx_t *mlx, t_element *element);
t_element		*ft_gen_player(t_element *element);

//solve.c
int				ft_check_if_reachable(t_element element, int y,
					int x, int *value);
char			**ft_cpy_map(t_element element, char **map);

//textures_to_window.c
void			ft_valere(mlx_t *mlx, int height, int width, t_element *element);
void			ft_collectible(mlx_t *mlx, int height, int width, t_element *element);
void			ft_exit(mlx_t *mlx, int height, int width, t_element *element);
void			ft_enemy(mlx_t *mlx, int height, int width, t_element *element);
void			ft_open_exit(t_element *element);

//valere_move.c
void			ft_movement(mlx_key_data_t keydata, void *data);
int				ft_next_pos(int32_t height, int32_t width,
					char key, char **map);
void			ft_add_step(t_element *element_ptr, int32_t *posx,
					int32_t *posy, char key);

//validate.c
void			ft_verify_map(char **map, t_element *element);
void			ft_check_items(t_element *element);
void			ft_verify_counts(t_element *element);
void			ft_count_column(t_element *element);
void			ft_exit_game(t_element *element);


//wall_and_floor.c
void			*ft_wall(int height, int width, t_element *element);
void			*ft_floor(int height, int width, t_element *element);

#endif