/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:43:32 by achu              #+#    #+#             */
/*   Updated: 2024/09/05 18:10:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

int	ft_strlen(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && search_base(str[i], base) != -1)
		i++;
	return (i);
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		len;
	long	sum;

	i = -1;
	sign = 1;
	sum = 0;
	if (!ft_checkbase(base))
		return (0);
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	while (*str == 45 || *str == 43)
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	len = ft_strlen(str, base) - 1;
	while (i++ <= len || search_base(str[i], base) != -1)
	{
		sum += search_base(str[i], base)
			* ft_power(ft_strlen(base, base), len - i);
	}
	return (sum * sign);
}

/*
int main()
{
    printf("%i",ft_atoi_base("    ---10100011010000011000001", "001"));
}
*/
