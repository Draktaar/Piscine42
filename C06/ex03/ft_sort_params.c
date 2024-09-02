/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:17:26 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 17:27:58 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	my_arglen(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
		i++;
	return (i);
}

void	my_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i;
		while (j < argc - 1)
		{
			if (my_strcmp(argv[i], argv[j + 1]) > 0)
				my_swap(&argv[i], &argv[j + 1]);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		write (1, argv[i], my_arglen(argv[i]));
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
