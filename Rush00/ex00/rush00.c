/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 11:01:48 by achu              #+#    #+#             */
/*   Updated: 2024/08/18 19:28:36 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	border(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
			ft_putchar(111);
		else
			ft_putchar(45);
		i++;
	}
	ft_putchar('\n');
}

void	body(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
			ft_putchar(124);
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	j = 0;
	while (j < y)
	{
		if (j == 0 || j == y - 1)
			border(x);
		else
			body(x);
		j++;
	}
}
