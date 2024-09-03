/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:27:42 by achu              #+#    #+#             */
/*   Updated: 2024/09/02 21:16:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	my_strjlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

int	my_alloclen(int size, char *strs[], char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += my_strjlen(strs[i]);
		if (i < size - 1)
			len += my_strjlen(sep);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char *strs[], char *sep)
{
	int		i;
	int		j;
	int		len;
	char	*cat;

	i = -1;
	len = -1;
	cat = (char *)malloc((my_alloclen(size, strs, sep) + 1) * sizeof(char));
	while (++i < size)
	{
		j = -1;
		while (++j < my_strjlen(strs[i]))
			cat[++len] = strs[i][j];
		if (i < size - 1)
		{
			j = -1;
			while (++j < my_strjlen(sep))
				cat[++len] = sep[j];
		}
	}
	cat[++len] = '\0';
	return (cat);
}

// int	main(void)
// {
// 	char *str[] = { "", "Hello", "", "world"};
// 	char sep[] = "-";
// 	char *test;

// 	test = ft_strjoin(0, str, sep);
// 	printf("%s",  test);
// }
