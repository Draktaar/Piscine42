/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:09:03 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 21:10:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str);
int	ft_nblen(int nb, int div);
int	ft_power(int nbr, int power);
int	ft_checkbase(char *base);
int	search_base(char c, char *base);

char	*ft_totoa(char *str, char *base)
{
	int		i;
	int		j;
	int		temp;
	char	*itoa;

	i = 0;
	j = 0;
	temp = 1;
	itoa = malloc(1000 * sizeof(char));
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32
		|| (str[i] == 43 || str[i] == 45))
		i++;
	while (search_base(str[i], base) != -1)
	{
		itoa[j] = str[i];
		j++;
		i++;
	}
	itoa[j] = '\0';
	return (itoa);
}

int	ft_convert_dec_base(char *nbr, char *base)
{
	int		i;
	int		len;
	long	sum;

	i = 0;
	sum = 0;
	len = ft_strlen(nbr) - 1;
	while (i <= len)
	{
		sum += search_base(nbr[i], base) * ft_power(ft_strlen(base), len - i);
		i++;
	}
	return (sum);
}

char	*ft_convert_any_base(long nbr, char *base_to)
{
	int		i;
	int		div;
	int		len;
	int		temp;
	char	*base;

	i = 0;
	div = ft_strlen(base_to);
	len = ft_nblen(nbr, div);
	base = (char *)malloc ((len + 1) * sizeof(char));
	if (nbr == 0)
	{
		base[0] = '0';
		return (base);
	}
	while (0 < nbr)
	{
		temp = nbr % div;
		if (0 <= temp)
			base[len - i - 1] = base_to[temp];
		nbr /= div;
		i++;
	}
	base[i] = '\0';
	return (base);
}

char	*ft_sign(char *nbr, char *str)
{
	int		i;
	int		sign;
	char	*result;

	i = -1;
	sign = 1;
	while (!((48 <= nbr[i] && nbr[i] <= 57) || (65 <= nbr[i] && nbr[i] <= 90)
			|| (97 <= nbr[i] && nbr[i] <= 122)))
	{
		if (nbr[++i] == 45)
			sign *= -1;
	}
	if (sign < 0 && str[0] != '0')
	{
		i = -1;
		result = (char *)malloc ((1 + ft_strlen(str) + 1) * sizeof(char));
		result[0] = '-';
		while (str[++i] != '\0')
			result[i + 1] = str[i];
		result[++i] = '\0';
		return (result);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*converted_base;
	char	*totoa;

	if (!ft_checkbase(base_from) || !ft_checkbase(base_to))
		return (NULL);
	totoa = ft_totoa(nbr, base_from);
	converted_base = ft_convert_any_base(
			ft_convert_dec_base(totoa, base_from), base_to);
	converted_base = ft_sign(nbr, converted_base);
	return (converted_base);
}

// int	main(int argc, char const *argv[])
// {
// 	char	*test;

// 	test = ft_convert_base("-----1010", "01", "0123456789ABCDEF");
// 	printf("%s", test);
// 	return (0);
// }
