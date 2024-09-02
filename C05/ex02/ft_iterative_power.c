/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:50:01 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 14:52:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
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
// int main(void)
// {
//	printf("%i", ft_iterative_power(-6, 5));
// }
