/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:54:56 by achu              #+#    #+#             */
/*   Updated: 2024/08/22 19:26:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb && i < 46341)
	{
		if (nb % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (i <= 2147483647)
	{
		if (my_is_prime(i))
			return (i);
		i++;
	}
	return (0);
}
// int main(void)
// {
// 	printf("%i", ft_find_next_prime(32));
// }
