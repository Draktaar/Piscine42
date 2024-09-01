/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:07:41 by achu              #+#    #+#             */
/*   Updated: 2024/08/18 19:33:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	head(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
			ft_putchar(65);
		else
			ft_putchar(66);
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
			ft_putchar(66);
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	tail(int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 || i == size - 1)
			ft_putchar(67);
		else
			ft_putchar(66);
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
		if (j == 0)
			head(x);
		else if (j == y - 1)
			tail(x);
		else
			body(x);
		j++;
	}
}
