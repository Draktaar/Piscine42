/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:29:27 by achu              #+#    #+#             */
/*   Updated: 2024/09/04 20:01:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_solvemap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_map	ft_init_map(char **map)
{
	int		len;
	t_map	map_data;

	len = ft_strlen(map[0]);
	map_data.blank = map[0][len - 3];
	map_data.wall = map[0][len - 2];
	map_data.ink = map[0][len - 1];
	map_data.map = map;
	return (map_data);
}

void	ft_print_map(t_map mdata)
{
	int	i;
	int	j;

	i = 1;
	while (mdata.map[i] != 0)
	{
		j = 0;
		while (mdata.map[i][j] != '\0')
		{
			write(1, &mdata.map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_draw_map(t_map mdata, t_square square)
{
	int	row;
	int	col;

	row = 0;
	while (row < square.size - 1)
	{
		col = 0;
		while (col < square.size - 1)
		{
			mdata.map[square.y + row][square.x + col] = mdata.ink;
			col++;
		}
		row++;
	}
}
