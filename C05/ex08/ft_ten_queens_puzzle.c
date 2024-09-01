/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:17:37 by achu              #+#    #+#             */
/*   Updated: 2024/08/28 13:54:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_grid(int *grid)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = grid[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_valid(int *grid, int x)
{
	int	i;
	int	diff_row;
	int	diff_col;

	i = 0;
	while (i < x)
	{
		diff_row = grid[x] - grid[i];
		diff_col = x - i;
		if (diff_col == diff_row || diff_col == -diff_row)
			return (0);
		if (grid[i] == grid[x])
			return (0);
		i++;
	}
	return (1);
}

int	ft_solve(int *grid, int x)
{
	int	i;
	int	sum;

	if (x == 10)
	{
		print_grid(grid);
		return (1);
	}
	i = 0;
	sum = 0;
	while (i < 10)
	{
		grid[x] = i;
		if (ft_is_valid(grid, x))
			sum += ft_solve(grid, x + 1);
		i++;
	}
	return (sum);
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10];

	return (ft_solve(grid, 0));
}

// int	main(void)
// {
// 	printf("%i", ft_ten_queens_puzzle());
// }
