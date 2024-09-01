/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:05:36 by bduval            #+#    #+#             */
/*   Updated: 2024/08/31 18:06:30 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_space_number(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	return (0);
}

char	*read_spaces_signs(char *str)
{
	int	sign;

	while (is_space_number(*str) == 1)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (sign == -1)
		return (NULL);
	return (str);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*read_number(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while (is_space_number(str[i]) == 2)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	ft_strncpy(result, str, i);
	return (result);
}

char	*clean_arg(char *str)
{
	str = read_spaces_signs(str);
	if (!str)
		return (NULL);
	str = read_number(str);
	return (str);
}
/*
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	main(int ac, char **av)
{
	if (ac >= 1)
	{
		printf("Originale : %s\n", av[1]);
		printf("Result : %s\n", clean_arg(av[1]));
	}
	return (0);
}
*/
