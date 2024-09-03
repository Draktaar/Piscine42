/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:30:03 by achu              #+#    #+#             */
/*   Updated: 2024/08/30 21:08:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_array(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_check_charset(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !ft_check_charset(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_memo_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !ft_check_charset(str[i], charset))
		i++;
	return (i);
}

char	*ft_alloc(char *str, char *charset)
{
	int		i;
	int		len;
	char	*memo;

	i = 0;
	len = ft_memo_len(str, charset);
	memo = (char *)malloc ((len + 1) * sizeof(char));
	while (i < len)
	{
		memo[i] = str[i];
		i++;
	}
	memo[i] = '\0';
	return (memo);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc ((ft_len_array(str, charset) + 1) * sizeof(char *));
	while (*str)
	{
		while (*str != '\0' && ft_check_charset(*str, charset))
			str++;
		if (*str != '\0')
		{
			split[i] = ft_alloc(str, charset);
			i++;
		}
		while (*str != '\0' && !ft_check_charset(*str, charset))
			str++;
	}
	split[i] = 0;
	return (split);
}

// int main()
// {
//     char **split;
//     char test[] ="test bonjour    e";
//     char sep[] = " e";

//     split = ft_split(test, sep);
//     for (int i = 0; split[i] != 0; i++)
//     {
//         printf("%s\n", split[i]);
//     }
// }
