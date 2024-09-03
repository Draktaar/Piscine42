/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:09:58 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 16:21:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_nblen(int nb, int div)
{
	int	i;
	int	temp;
	int	count;

	i = 1;
	count = 0;
	while (0 < nb)
	{
		temp = nb % div;
		if (0 <= temp)
			count++;
		nb /= div;
		i++;
	}
	return (count);
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

int	ft_power(int nb, int power)
{
	int	i;
	int	pow;

	i = 1;
	pow = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (i < power)
	{
		nb *= pow;
		i++;
	}
	return (nb);
}

int	ft_checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (!((48 <= base[i] && base[i] <= 57)
				|| (65 <= base[i] && base[i] <= 90)
				|| (97 <= base[i] && base[i] <= 122)))
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
