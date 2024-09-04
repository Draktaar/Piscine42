/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:56:17 by kbaridon          #+#    #+#             */
/*   Updated: 2024/08/29 13:56:33 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_count_words(char *str, char *charset)
{
	int	compteur;
	int	i;

	i = 0;
	compteur = 0;
	while (str[i])
	{
		if (!(is_charset(str + i, charset)))
		{
			compteur++;
			while (str[i] && !(is_charset(str + i, charset)))
				i++;
		}
		else
			i++;
	}
	return (compteur);
}

int	is_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[0] && i < ft_len(charset))
	{
		if (str[0] == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	strn_cpy(char *dest, char *src, int i, unsigned int n)
{
	unsigned int	x;

	x = 0;
	while (src[i] && x < n)
	{
		dest[x] = src[i];
		i++;
		x++;
	}
	dest[x] = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		tab[2];
	int		i;

	i = 0;
	tab[1] = 0;
	result = malloc((ft_count_words(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (malloc(1));
	while (str[i])
	{
		if (is_charset(str + i, charset))
			i++;
		else
		{
			tab[0] = i;
			while (!(is_charset(str + tab[0], charset)) && str[tab[0]])
				tab[0] = tab[0] + 1;
			result[tab[1]] = malloc((tab[0] - i + 1) * sizeof(char));
			i = strn_cpy(result[tab[1]], str, i, tab[0] - i);
			tab[1] = tab[1] + 1;
		}
	}
	result[tab[1]] = NULL;
	return (result);
}
