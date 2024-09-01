/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:43:36 by achu              #+#    #+#             */
/*   Updated: 2024/08/21 18:54:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_is_non_printable(char str)
{
	if (31 >= str || str >= 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;
	int	test;

	test = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (my_is_non_printable(str[i]))
		{
			write(1, "\\", 1);
			write(1, (unsigned int)&str[i], 2);
		}
		write(1, &str[i], 1);
		i++;
	}
}
