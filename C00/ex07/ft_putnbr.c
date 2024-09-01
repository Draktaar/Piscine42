/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:41:27 by achu              #+#    #+#             */
/*   Updated: 2024/08/15 22:34:24 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isneg(int nb)
{
	if (nb < 0)
	{
		ft_putchar(45);
		return (nb *= -1);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int	pow;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	pow = 1;
	nb = ft_isneg(nb);
	while (nb / pow >= 10)
	{
		pow *= 10;
	}
	ft_putchar(48 + nb / pow);
	if (nb % pow == 0 && pow == 1)
		return ;
	else
		ft_putnbr(nb % pow);
}
