/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:20:44 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/18 19:14:31 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_long	*init_game(char **map_plant)
{
	t_long	*game;

	game = (t_long *) malloc (sizeof(t_long));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	game->collect_count = 0;
	game->total_moves = 0;
	game->map = map_plant;
	game->win = mlx_new_window(game->mlx, (ft_strlen(map_plant[0]) * 32), (ft_biglen(map_plant) * 32), "teste");
	game->img.x = 32;
	game->img.y = 32;
	game->player.x = -1;
	game->player.y = -1;
	return (game);
}

static void	init_images(t_long *game, t_map *map)
{
	map->floor.img = mlx_xpm_file_to_image(game->mlx, \
		"grass_1.xpm", &game->img.x, &game->img.y);
	map->obstacle.img = mlx_xpm_file_to_image(game->mlx, \
		"tree.xpm", &game->img.x, &game->img.y);
	map->wall.img = mlx_xpm_file_to_image(game->mlx, \
		"water_1.xpm", &game->img.x, &game->img.y);
	map->collectible.img = mlx_xpm_file_to_image(game->mlx, \
		"key.xpm", &game->img.x, &game->img.y);
	map->exit_unstable.img = mlx_xpm_file_to_image(game->mlx, \
		"portal.xpm", &game->img.x, &game->img.y);
	game->player.player_down = mlx_xpm_file_to_image(game->mlx, \
		"Male_down.xpm", &game->img.x, &game->img.y);
	game->player.player_up = mlx_xpm_file_to_image(game->mlx, \
		"Male_up.xpm", &game->img.x, &game->img.y);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, \
		"Male_left.xpm", &game->img.x, &game->img.y);
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, \
		"Male_right.xpm", &game->img.x, &game->img.y);
	map->exit_stable.img = mlx_xpm_file_to_image(game->mlx, \
		"portal_stable.xpm", &game->img.x, &game->img.y);
	map->enemy.img = mlx_xpm_file_to_image(game->mlx, \
		"Enemy_front.xpm", &game->img.x, &game->img.y);
}

static void	builder_2(t_map *map, t_long *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
		map->collectible.img, (x * 32), (y * 32));
	else if (game->map[y][x] == 'E')
	{
		if (game->collect_count > 0)
			mlx_put_image_to_window(game->mlx, game->win, \
			map->exit_unstable.img, (x * 32), (y * 32));
		else
			mlx_put_image_to_window(game->mlx, game->win, \
			map->exit_stable.img, (x * 32), (y * 32));
	}
	else if (game->map[y][x] == 'P' && \
	game->player.x == -1 && game->player.y == -1)
	{
		game->player.x = (x * 32);
		game->player.y = (y * 32);
	}
	else if (game->map[y][x] == 'X')
		mlx_put_image_to_window(game->mlx, game->win, \
		map->enemy.img, (x * 32), (y * 32));
}

static void	builder(t_map *map, t_long *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		if (y == 0 || y == ft_biglen(game->map) - 1 \
		|| x == 0 || x == (int)ft_strlen(game->map[y]) - 1)
			mlx_put_image_to_window(game->mlx, game->win, \
			map->wall.img, (x * 32), (y * 32));
		else
			mlx_put_image_to_window(game->mlx, game->win, \
			map->obstacle.img, (x * 32), (y * 32));
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, \
		map->floor.img, (x * 32), (y * 32));
	}
	builder_2(map, game, x, y);
}

static void	animation(t_long *game, int keycode)
{
	if (keycode == D)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.player_right, game->player.x, game->player.y);
	else if (keycode == A)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.player_left, game->player.x, game->player.y);
	else if (keycode == S)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.player_down, game->player.x, game->player.y);
	else if (keycode == W)
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.player_up, game->player.x, game->player.y);
	else
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player.player_down, game->player.x, game->player.y);
}

void	build_map(t_long *game, int keycode)
{
	t_map		*map;
	int			x;
	int			y;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return ;
	init_images(game, map);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			builder(map, game, x, y);
			x++;
		}
		y++;
	}
	animation(game, keycode);
	mlx_string_put(game->mlx, game->win, 0, 0, 0, ft_itoa(game->total_moves));
	game->total_moves += 1;
}
