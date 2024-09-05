/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:23:00 by achu              #+#    #+#             */
/*   Updated: 2024/09/05 18:23:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

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

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if ((9 <= base[i] && base[i] <= 13) || base[i] == 32
			|| (base[i] == 45 || base[i] == 43))
			return (0);
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	c;
	char	div;

	div = ft_strlen(base);
	if (!ft_checkbase(base))
		return ;
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

/*
int main ()
{
	ft_putnbr_base(-320947285, "0123456789ABCDEF");
}
*/
