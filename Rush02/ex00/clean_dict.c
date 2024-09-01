/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:09:33 by bduval            #+#    #+#             */
/*   Updated: 2024/09/01 14:31:04 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_printable(char c)
{
	if (c > ' ' && c <= '~')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

void	ft_clean_inner_spaces(char *str)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
	{
		count = 0;
		while (is_space(str[i]))
		{
			count++;
			i++;
		}
		while (is_printable(str[i]))
		{
			if (count)
			{
				str[i - count] = str[i];
				str[i] = ' ';
			}
			i++;
		}
		i = i + 1 - count;
	}
	return ;
}

void	ft_clean_last_spaces(char *str)
{
	int	i;
	int	last_is_space;
	int	last_index;

	i = 0;
	last_is_space = 0;
	while (str[i])
	{
		last_index = i;
		while (is_space(str[i]))
		{
			last_is_space = 1;
			i++;
		}
		while (is_printable(str[i]))
		{
			last_is_space = 0;
			i++;
		}
	}
	if (last_is_space)
		str[last_index] = '\0';
}

void	ft_clean_dict(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_clean_inner_spaces(tab[i]);
		ft_clean_last_spaces(tab[i]);
		i++;
	}
	return ;
}
