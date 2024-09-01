/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:46:27 by achu              #+#    #+#             */
/*   Updated: 2024/08/19 19:34:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_arglen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		write (1, argv[i], my_arglen(argv[i]));
		write (1, "\n", 1);
		i--;
	}
	return (0);
}
