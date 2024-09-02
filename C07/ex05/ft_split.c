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

int	ft_is_charset(char c, char *charset)
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
	int	is_set;
	int	count;

	i = 0;
	is_set = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) && !is_set)
		{
			count++;
			is_set = 1;
		}
		else if (!ft_is_charset(str[i], charset) && is_set)
			is_set = 0;
		i++;
	}
	return (count);
}

char	*ft_alloc(char *start, char *end)
{
	int		i;
	int		len;
	char	*memo;

	i = 0;
	len = end - start;
	memo = (char *)malloc ((len + 1) * sizeof(char));
	while (i < len)
	{
		memo[i] = start[i];
		i++;
	}
	memo[i] = '\0';
	return (memo);
}

void	ft_end(char **split, char *temp, char *str, int i)
{
	if (temp)
		split[i] = ft_alloc(temp, str);
	split[++i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		is_set;
	char	*temp;
	char	**split;

	i = 0;
	is_set = 1;
	split = (char **)malloc ((ft_len_array(str, charset) + 1) * sizeof(char *));
	while (*str)
	{
		if (ft_is_charset(*str, charset) && !is_set)
		{
			split[i++] = ft_alloc(temp, str);
			is_set = 1;
			temp = NULL;
		}
		else if (!ft_is_charset(*str, charset) && is_set)
		{
			is_set = 0;
			temp = str;
		}
		str++;
	}
	ft_end(split, temp, str, i);
	return (split);
}

int main()
{
    char **split;
    char test[] = "       20       fifty            ";
    char sep[] = "";

    split = ft_split(test, sep);
    for (int i = 0; split[i] != 0; i++)
    {
        printf("%s\n", split[i]);
    }
}
