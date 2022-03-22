/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:22:47 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/22 18:03:13 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(int fd)
{
	char	*map;
	char	*tmp;
	char	*returned;
	char	**test;

	returned = get_next_line(fd);
	map = ft_strdup("");
	while (returned != NULL)
	{
		tmp = ft_strjoin(map, returned);
		free(map);
		map = tmp;
		free(returned);
		returned = get_next_line(fd);
	}
	test = ft_split(map, '\n');
	free(map);
	return (test);
}
