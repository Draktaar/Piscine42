/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:07:41 by achu              #+#    #+#             */
/*   Updated: 2024/08/17 22:24:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_strstrlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	my_strcmp(char const *str, char const *cmp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		len;

	i = 0;
	len = my_strstrlen(to_find);
	if (len == 0)
	{
		return (str);
	}
	while (str[i] != '\0')
	{
		if (my_strcmp(&str[i], to_find, len))
			return (&str[i]);
		i++;
	}
	return (NULL);
}
