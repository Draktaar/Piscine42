/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:48:23 by achu              #+#    #+#             */
/*   Updated: 2024/08/29 22:04:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (tab);
	i = min;
	tab = (int *) malloc ((max - min) * sizeof(int));
	while (i < max)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

// int main()
// {
//     int *test;
//     test = ft_range(-19, 50);
//     int i = -19;
//     while (i < 50)
//     {
//         printf("%i\n",  test[i]);
//         i++;
//     }
// }
