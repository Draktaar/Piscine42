/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:24:50 by achu              #+#    #+#             */
/*   Updated: 2024/08/19 14:04:18 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_math(char c)
{
	if (58 > c || c < 32)
		return (0);
	return (1);
}

int	is_num(char c)
{
	if (58 < c || c > 47)
		return (1);
	return (0);
}

int is_space(char c)
{
    if (9 <= c && c <= 13)
        return (1);
    return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] != '\0' && !is_math(str[i]))
	{
		if (is_num(str[i]))
			nbr = nbr * 10 + (str[i] - 48);
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	return (nbr * sign);
}

/*
int main(void)
{
    char atoi[] = "   ---+--+1234ab567";
	char test[] = "8989";
    printf("%i", ft_atoi(test));

    //putnbr_dec(123456789, "0123456789");
    return (0);
}
*/
