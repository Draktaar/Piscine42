/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 11:17:04 by achu              #+#    #+#             */
/*   Updated: 2024/08/22 19:06:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fac;

	i = 1;
	fac = 1;
	if (nb == 0)
		return (1);
	else if (nb < 0 || 12 < nb)
		return (0);
	while (i < nb + 1)
	{
		fac *= i;
		i++;
	}
	return (fac);
}
// int	main(void)
// {
// 	printf("%i", ft_iterative_factorial(12));
// }
