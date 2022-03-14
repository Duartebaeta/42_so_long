/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:25:54 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/14 18:11:33 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_special(char c)
{
	static int	collectible_count = 0;
	static int	exit_count = 0;
	static int	player_count = 0;

	if (c == 'C')
		collectible_count++;
	else if (c == 'E')
		exit_count++;
	else if (c == 'P')
		player_count++;
	else if (c == '%')
	{
		if (collectible_count < 1 || exit_count < 1 || player_count < 1)
			return (-4);
	}
	return (collectible_count);
}

static int	check_first_last(char *row)
{
	int	counter;

	counter = 0;
	while(row[counter] != '\0')
	{
		if (row[counter] != '1')
			return (1);
		counter++;
	}
	return (0);
}

int	check_middle(char *row)
{
	int	counter;

	counter = 0;
	if (row[0] != '1' || row[ft_strlen(row) - 1] != '1')
		return (-1);
	while (row[counter] != '\0')
	{
		if (ft_strchr("01CEP", row[counter]) == NULL)
			return (-2);
		if (row[counter] == 'C' || row[counter] == 'E' || row[counter] == 'P')
			check_special(row[counter]);
		counter++;
	}
	return (0);
}

int	check_rows(char **map)
{
	int	row;
	int	len;

	row = 0;
	len = ft_strlen(map[0]);
	while (map[row] != NULL)
	{
		if ((int)(ft_strlen(map[row])) != len)
			return (-1);
		if (row == 0 || map[row + 1] == NULL)
		{
			if (check_first_last(map[row]) == 1)
				return (-2);
		}
		else
		{
			if (check_middle(map[row]) < 0)
				return (-3);
		}
		row++;
	}
	return (check_special('%'));
}