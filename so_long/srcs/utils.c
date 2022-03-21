/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:11:16 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/21 17:02:03 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_biglen(char **big)
{
	int	counter;

	counter = 0;
	while (big[counter] != NULL)
		counter++;
	return (counter);
}

void	print_big(char **big)
{
	int	counter;

	counter = 0;
	while (big[counter])
	{
		ft_printf("%s\n", big[counter]);
		counter++;
	}
}

void	animation(t_long *game, int keycode)
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
