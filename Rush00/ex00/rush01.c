/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmicael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:52:23 by mmicael           #+#    #+#             */
/*   Updated: 2024/08/18 20:01:26 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(int c, int x)
{
	if (c == 0)
		ft_putchar('/');
	else if (c == x - 1)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	mid(int c, int x)
{
	if (c == 0 || c == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	bot(int c, int x)
{
	if (c == 0)
		ft_putchar('\\');
	else if (c == x - 1)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	rush(int x, int y)
{
	int	c;
	int	l;

	l = 0;
	while (l < y)
	{
		c = 0;
		while (c < x)
		{
			if (l == 0)
				top(c, x);
			else if (l == y - 1)
				bot(c, x);
			else
				mid(c, x);
			c++;
		}
		ft_putchar('\n');
	l++;
	}
}
