/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:04:04 by achu              #+#    #+#             */
/*   Updated: 2024/08/29 19:44:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*my_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *) malloc((my_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*temp;
	t_stock_str	*stock;

	i = 0;
	stock = malloc((ac + 1) * sizeof(t_stock_str));
	if (stock == NULL)
		return (NULL);
	while (i < ac)
	{
		stock[i].str = av[i];
		temp = my_strdup(av[i]);
		if (!temp)
			return (NULL);
		stock[i].copy = temp;
		stock[i].size = my_strlen(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
