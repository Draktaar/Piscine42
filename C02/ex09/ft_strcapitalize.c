/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:11:39 by achu              #+#    #+#             */
/*   Updated: 2024/08/18 17:58:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_is_lower(char str)
{
	if (96 >= str || str >= 123)
		return (0);
	return (1);
}

int	my_is_upper(char str)
{
	if (64 >= str || str >= 91)
		return (0);
	return (1);
}

int	my_is_alphanum(char str)
{
	if (65 <= str && str <= 90)
		return (1);
	else if (97 <= str && str <= 122)
		return (1);
	else if (48 <= str && str <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (my_is_lower(str[i]) && !my_is_alphanum(str[i - 1]))
			str[i] -= 32;
		else if (my_is_upper(str[i]) && my_is_alphanum(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
