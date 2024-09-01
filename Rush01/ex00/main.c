/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:13:28 by mcamaren          #+#    #+#             */
/*   Updated: 2024/08/25 23:30:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	g_grid[6][6];

void	print_grid(int size)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < size + 1)
	{
		j = 1;
		while (j < size + 1)
		{
			c = g_grid[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	init_grid(int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size + 2)
	{
		j = 0;
		while (j < size + 2)
		{
			g_grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	edge_border(int size, char *str)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	while (i <= size)
	{
		g_grid[0][i] = str[len] - 48;
		len += 2;
		i++;
	}
	i = 1;
	while (i <= size)
	{
		g_grid[size + 1][i] = str[len] - 48;
		len += 2;
		i++;
	}
}

void	edge_side(int size, char *str)
{
	int	i;
	int	len;

	i = 1;
	len = 16;
	while (i <= size)
	{
		g_grid[i][0] = str[len] - 48;
		len += 2;
		i++;
	}
	i = 1;
	while (i <= size)
	{
		g_grid[i][size + 1] = str[len] - 48;
		len += 2;
		i++;
	}
}

int	is_line_left(int y)
{
	int	i;
	int	count;
	int	cur_height;

	i = 1;
	count = 0;
	cur_height = 0;
	while (i <= 4)
	{
		if (cur_height < g_grid[y][i])
		{
			cur_height = g_grid[y][i];
			count++;
		}
		i++;
	}
	if (count <= g_grid[y][0])
		return (1);
	return (0);
}

int	is_line_right(int y)
{
	int	i;
	int	count;
	int	cur_height;

	i = 4;
	count = 0;
	cur_height = 0;
	while (i >= 1)
	{
		if (cur_height < g_grid[y][i])
		{
			cur_height = g_grid[y][i];
			count++;
		}
		i--;
	}
	if (count <= g_grid[y][5])
		return (1);
	return (0);
}

int	is_col_up(int x)
{
	int	i;
	int	count;
	int	cur_height;

	i = 1;
	count = 0;
	cur_height = 0;
	while (i <= 4)
	{
		if (cur_height < g_grid[i][x])
		{
			cur_height = g_grid[i][x];
			count++;
		}
		i++;
	}
	if (count <= g_grid[0][x])
		return (1);
	return (0);
}

int	is_col_down(int x)
{
	int	i;
	int	count;
	int	cur_height;

	i = 4;
	count = 0;
	cur_height = 0;
	while (i >= 1)
	{
		if (cur_height < g_grid[i][x])
		{
			cur_height = g_grid[i][x];
			count++;
		}
		i--;
	}
	if (count <= g_grid[5][x])
		return (1);
	return (0);
}

int	is_valid(int x, int y, int nb)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (g_grid[y][i] == nb || g_grid[i][x] == nb)
			return (0);
		i++;
	}
	if (!is_line_left(y) || !is_line_right(y))
		return (0);
	if (!is_col_up(x) || !is_col_down(x))
		return (0);
	return (1);
}

int	solve(int x, int y)
{
	int	i;

	if (y == 5)
		return (1);
	else if (x == 5)
		return (solve(1, y + 1));
	else if (g_grid[y][x] != 0)
		return (solve(x + 1, y));
	else
	{
		i = 1;
		while (i <= 4)
		{
			if (is_valid(x, y, i))
			{
				g_grid[y][x] = i;
				if (solve(x + 1, y))
					return (1);
				g_grid[y][x] = 0;
			}
			i++;
		}
		return (0);
	}
}

int	main(int arg, char *argv[])
{
	arg++;
	init_grid(4);
	edge_border(4, argv[1]);
	edge_side(4, argv[1]);
	if (solve(1, 1))
		print_grid(4);
	else
		write(1, "Error", 5);
}
