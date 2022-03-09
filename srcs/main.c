/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:31:01 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/09 19:29:19 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int close_window()
{
	exit(EXIT_SUCCESS);
	return 0;
}

int main()
{
	t_long	*game;

	game = (t_long *) malloc (sizeof(t_long));
	if (!game)
		return (0);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, X_SIZE, Y_SIZE, "teste");
	game->img.img = mlx_xpm_file_to_image(game->mlx, "red.xpm", &game->x, &game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_hook(game->win, 17, 0L, close_window, &game);
	mlx_loop(game->mlx);
	
	return 0;
}

