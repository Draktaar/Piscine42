/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:29 by achu              #+#    #+#             */
/*   Updated: 2024/09/04 13:06:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"
#include "../includes/ft_solvemap.h"

int	ft_check_square(t_map mdata, t_square square, int x, int y)
{
	int	row;
	int	col;

	row = 0;
	while (row < square.size)
	{
		col = 0;
		while (col < square.size)
		{
			if (mdata.map[y + row][x + col] != mdata.blank)
				return (0);
			col++;
		}
		row++;
	}
	return (1);
}

void	ft_resolve(t_map mdata, t_square *square)
{
	int	i;
	int	j;

	i = 1;
	while (i + (*square).size < count_row(mdata.map))
	{
		j = 0;
		while (j + (*square).size < ft_strlen(mdata.map[i]))
		{
			while (ft_check_square(mdata, (*square), j, i))
			{
				(*square).x = j;
				(*square).y = i;
				(*square).size++;
			}
			j++;
		}
		i++;
	}
}
