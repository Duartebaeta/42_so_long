/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:21:22 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/14 18:29:33 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include "../libs/libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef X_SIZE
#define X_SIZE 1920
#endif

#ifndef Y_SIZE
#define Y_SIZE 1080
#endif

typedef struct s_image
{
	void	*img;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}t_img;

typedef struct s_player
{
	void	*playerImage;
	int		x;
	int		y;
}t_player;

typedef struct s_long
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_player	player;
	int		x;
	int		y;
}t_long;

char	**read_map(char *filename);
int		check_rows(char **map);
int		check_middle(char *row);
int		custom_error(int error, char **map);

#endif