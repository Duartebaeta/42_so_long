/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:48:00 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/15 14:52:14 by dhomem-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_irregular_size(char **map)
{
	int	len;
	int	counter;

	counter = 0;
	len = ft_strlen(map[0]);
	while (ft_strlen(map[counter]) == ft_strlen(map[counter + 1]) && map[counter + 1])
		counter++;
	return (counter + 1);
}

static int	get_specific(int error, char *row)
{
	int	counter;

	counter = 0;
	if (error == -1)
		return (0);
	while (row[counter])
	{
		if (ft_strchr("01CEP", row[counter]) == NULL)
			break ;
		counter++;
	}
	return (counter + 1);
}

int	custom_error(int error, char **map)
{
	int	counter;
	int	ret;
	int	tmp;

	if (error == -1)
		ft_printf("Error\nIrregular size on line %i\n", get_irregular_size(map));
	else if (error == -2)
		ft_printf("Error\nMap must be surrounded by walls\n");
	else if (error == -3)
	{
		counter = 0;
		tmp = 0;
		while (tmp == 0 && map[counter + 1] != NULL)
			tmp = check_middle(map[counter++]);
		ret = get_specific(tmp, map[counter - 1]);
		if (ret == 0)
			ft_printf("Error\nMap must be surrounded by walls\n");
		else
			ft_printf("Error\nInvalid char on line %i col %i\n", counter, ret);
	}
	else if (error == -3)
		ft_printf("Error\nNot enough specials");
	if (error < 0)
		return (-1);
	return (0);
}
