/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:10 by achu              #+#    #+#             */
/*   Updated: 2024/08/19 19:33:04 by achu             ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		write (1, argv[i], my_arglen(argv[i]));
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
