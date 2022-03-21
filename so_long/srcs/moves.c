/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:31:45 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/21 17:01:06 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_legal(t_long	*game, char key, int x, int y)
{
	if (key == 'W')
	{
		if (game->map[y - 1][x] == '1')
			return (0);
	}
	else if (key == 'D')
	{
		if (game->map[y][x + 1] == '1')
			return (0);
	}
	else if (key == 'S')
	{
		if (game->map[y + 1][x] == '1')
			return (0);
	}
	else if (key == 'A')
	{
		if (game->map[y][x - 1] == '1')
			return (0);
	}
	game->total_moves += 1;
	return (1);
}

int	interactive(t_long *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collect_count -= 1;
	}
	else if ((game->map[y][x] == 'E' && game->collect_count == 0) || \
		game->map[y][x] == 'X')
		close_window();
	return (0);
}
