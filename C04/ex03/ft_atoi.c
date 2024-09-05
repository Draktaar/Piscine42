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

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != '\0' && (32 < str[i] && str[i] < 58))
	{
		if (str[i] == '-')
			sign *= -1;
		if (48 <= str[i] && str[i] <= 57)
			nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}

/*
int main(void)
{
    char atoi[] = "   ---+--+1234ab567";
	char test[] = "8989";
    printf("%i", ft_atoi(atoi));

    //putnbr_dec(123456789, "0123456789");
    return (0);
}
*/
