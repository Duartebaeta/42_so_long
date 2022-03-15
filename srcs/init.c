/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:20:44 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/15 19:37:19 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_params(t_long *game)
{
	game->img.x = 0;
	game->img.y = 0;
	game->player.x = 0;
	game->player.y = 0;
}

void	init_image(t_long *game)
{
	game->img.img = mlx_xpm_file_to_image(game->mlx, "black.xpm", &game->img.x, &game->img.y);
	game->player.playerImage = mlx_xpm_file_to_image(game->mlx, "Male-12-2.xpm", &game->player.x, &game->player.y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->player.playerImage, game->player.x, game->player.y);
}

t_long	*init_game()
{
	t_long	*game;

	game = (t_long *) malloc (sizeof(t_long));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, X_SIZE, Y_SIZE, "teste");
	return (game);
}

void	build_map(char **map)
{
	t_img	wall;
	
}