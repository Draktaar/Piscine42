/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:56:01 by achu              #+#    #+#             */
/*   Updated: 2024/09/01 17:56:03 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_helper.h"

char	*ft_base(int len);
char	*skip_zero(char *str);

int	ft_check(char *nbr, char **dico)
{
	int		i;
	int		len;
	char	*memo;

	i = 0;
	len = ft_arraylen(skip_zero(nbr));
	memo = ft_base(len);
	while (dico[i] != 0)
	{
		if (!ft_strcmp(memo, dico[i]))
			return (1);
		i += 2;
	}
	write(2, "Dict Error", 11);
	return (0);
}

int	ft_checkzero(char **stock, int i)
{
	while (stock[i] != 0)
	{
		if (ft_strcmp(stock[i], "000"))
			return (0);
		i++;
	}
	return (1);
}
