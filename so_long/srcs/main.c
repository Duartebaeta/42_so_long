/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:31:01 by dhomem-d          #+#    #+#             */
/*   Updated: 2023/01/27 01:42:42 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_long *game)
{	
	if (keycode == W && check_legal(game, 'W', \
		(game->player.x / 32), (game->player.y / 32)))
		game->player.y -= 32;
	if (keycode == S && check_legal(game, 'S', \
		(game->player.x / 32), (game->player.y / 32)))
		game->player.y += 32;
	if (keycode == D && check_legal(game, 'D', \
		(game->player.x / 32), (game->player.y / 32)))
		game->player.x += 32;
	if (keycode == A && check_legal(game, 'A', \
		(game->player.x / 32), (game->player.y / 32)))
		game->player.x -= 32;
	if (keycode == ESC)
		close_window();
	interactive(game, (game->player.x / 32), (game->player.y / 32));
	build_map(game, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_long	*game;

	(void) argc;
	map = read_map(open(argv[1], O_RDONLY));
	game = init_game(map);
	game->collect_count = check_rows(map);
	if (custom_error(game->collect_count, map) < 0)
		return (1);
	build_map(game, 1);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	free(game);
	free(map);
	return (0);
}
