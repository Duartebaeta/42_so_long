/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:31:01 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/15 16:38:24 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int close_window()
{
	exit(EXIT_SUCCESS);
	return 0;
}

int key_hook(int keycode, t_long *game)
{	
	if (keycode == W)
		game->player.y -= 32;
	if (keycode == S)
		game->player.y += 32;
	if (keycode == D)
		game->player.x += 32;
	if (keycode == A)
		game->player.x -= 32;
	if (keycode == ESC)
		close_window();
	mlx_put_image_to_window(game->mlx, game-> win, \
	game->img.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game-> win, \
	game->player.playerImage, game->player.x, game->player.y);
	return 0;
}

int main(int argc, char **argv)
{
	char	**map;
	t_long	*game;

	(void) argc;
	map = read_map(argv[1]);
	if (custom_error(check_rows(map), map) < 0)
		return (1);
	game = init_game();
	init_params(game);
	init_image(game);
	mlx_hook(game->win, 17, 0L, close_window, &game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);

	return 0;
}
