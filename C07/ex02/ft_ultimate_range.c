/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:31:36 by achu              #+#    #+#             */
/*   Updated: 2024/08/30 21:14:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	*range = (int *)malloc ((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (i);
}

// int main(void)
// {
//     int *range;
//     int min = -382357;
//     int max = 500;
//     int size;

//     size = ft_ultimate_range(&range, min, max);
//     printf("%d", size);
//     return (0);
// }
