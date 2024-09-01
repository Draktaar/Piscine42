/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:37:13 by achu              #+#    #+#             */
/*   Updated: 2024/08/22 19:21:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * my_recursive_power(nb, power - 1));
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= nb && i < 46341)
	{
		if (my_recursive_power(i, 2) == nb)
			return (i);
		i++;
	}
	return (0);
}
// int main(void)
// {
// 	printf("%i", ft_sqrt(25));
// }
