/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:21:22 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/21 17:06:00 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_water
{
	void	*water_1;
	void	*water_2;
	void	*water_3;
	void	*water_4;
	void	*water_5;
}t_water;

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
}t_img;

typedef struct s_map
{
	t_img	floor;
	t_img	wall;
	t_img	obstacle;
	t_img	exit_unstable;
	t_img	exit_stable;
	t_img	collectible;
	t_img	enemy;
}t_map;

typedef struct s_player
{
	void	*player_down;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	int		x;
	int		y;
}t_player;

typedef struct s_long
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	t_player	player;

	int			collect_count;
	int			total_moves;
}t_long;

typedef enum s_key {
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	ESC = 53
}	t_key;

char	**read_map(char *filename);
int		check_rows(char **map);
int		check_middle(char *row);
int		custom_error(int error, char **map);
t_long	*init_game(char **map);
void	init_params(t_long *game, char **map);
void	build_map(t_long *game, int keycode);
int		ft_biglen(char **big);
void	print_big(char **big);
int		check_legal(t_long	*game, char key, int x, int y);
int		close_window(void);
int		interactive(t_long *game, int x, int y);
int		water_animation(t_long *game);
void	animation(t_long *game, int keycode);

#endif