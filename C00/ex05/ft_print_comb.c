/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:26:46 by achu              #+#    #+#             */
/*   Updated: 2024/08/15 11:33:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (i++ < 9)
	{
		j = i;
		while (j++ < 9)
		{
			k = j;
			while (k++ < 9)
			{
				ft_putchar(48 + i);
				ft_putchar(48 + j);
				ft_putchar(48 + k);
				if (i == 7 && j == 8 && k == 9)
					return ;
				ft_putchar(44);
				ft_putchar(32);
			}
		}
	}
}
