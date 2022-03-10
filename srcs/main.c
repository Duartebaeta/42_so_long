/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:31:01 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/10 19:24:11 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int close_window()
{
	exit(EXIT_SUCCESS);
	return 0;
}

int key_hook(t_long game, int param)
{
	if (param == 17)
	{
		game.player.x += 200;
		mlx_put_image_to_window(game.mlx, game.win, game.player.playerImage, game.player.x, game.player.y);
	}
	return 1;
}

int main(int argc, char **argv)
{
	t_long	*game;

	game = (t_long *) malloc (sizeof(t_long));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, X_SIZE, Y_SIZE, "teste");
	game->img.img = mlx_xpm_file_to_image(game->mlx, "map.xpm", &game->x, &game->y);
	game->player.playerImage = mlx_xpm_file_to_image(game->mlx, "red.xpm", &game->player.x, &game->player.y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player.playerImage, game->player.x, game->player.y);
	mlx_hook(game->win, 17, 0L, close_window, &game);
	mlx_key_hook(game->win, key_hook, &game);
	mlx_loop(game->mlx);

	return 0;
}
