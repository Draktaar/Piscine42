/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:48:23 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 21:10:55 by achu             ###   ########.fr       */
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
		return (NULL);
	i = 0;
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

// int main()
// {
//     int *test;
//     int min = -50000;
//     int max = 500000;
//     test = ft_range(min, max);
//     int i = 0;
//     while (i < max - min)
//     {
//         printf("%i\n",  test[i]);
//         i++;
//     }
// }
