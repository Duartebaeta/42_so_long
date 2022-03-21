/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:22:47 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/21 17:01:39 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(char *filename)
{
	char	*map;
	char	*returned;
	int		fd;
	char	**test;

	fd = open(filename, O_RDONLY);
	returned = get_next_line(fd);
	map = ft_strdup("");
	while (returned != NULL)
	{
		map = ft_strjoin(map, returned);
		returned = get_next_line(fd);
	}
	test = ft_split(map, '\n');
	return (test);
}
