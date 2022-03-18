/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhomem-d <dhomem-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:11:16 by dhomem-d          #+#    #+#             */
/*   Updated: 2022/03/17 16:28:44 by dhomem-d         ###   ########.fr       */
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