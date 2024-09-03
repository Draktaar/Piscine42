/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:23:00 by achu              #+#    #+#             */
/*   Updated: 2024/08/19 13:58:27 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	search_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char c;
	char div;

	div = ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr < div)
	{
		c = base[nbr];
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_base(nbr / div, base);
		ft_putnbr_base(nbr % div, base);
	}
}

int main ()
{
	ft_putnbr_base(12314, "0123456789");
}
