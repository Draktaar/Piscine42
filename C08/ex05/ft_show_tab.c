/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:10:33 by achu              #+#    #+#             */
/*   Updated: 2024/08/29 15:21:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i++;
	}
	my_putchar('\n');
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_print(par[i].str);
		ft_putnbr(par[i].size);
		my_putchar('\n');
		ft_print(par[i].copy);
		i++;
	}
}

/*
int main(int ac, char **av)
{
    ft_show_tab(ft_strs_to_tab(ac, av));

    return 0;
}
*/