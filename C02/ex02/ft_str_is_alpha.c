/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:02:04 by achu              #+#    #+#             */
/*   Updated: 2024/08/18 16:56:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (0 <= str[i] && str[i] <= 64)
			return (0);
		else if (91 <= str[i] && str[i] <= 96)
			return (0);
		else if (123 <= str[i] && str[i] <= 127)
			return (0);
		i++;
	}
	return (1);
}
