/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:41:10 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/04 09:41:12 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	count_row(char **row)
{
	int	count;

	count = 1;
	while (row[count] != NULL)
		count++;
	return (count - 1);
}

int	is_valid_line(char *str, char **row)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (ft_len(row[0]) > 4)
	{
		while (row[0][i] >= '0' && row[0][i] <= '9' && row[0][i + 4] != '\0')
			i++;
	}
	if (!(str[count] == row[0][i + 1] || str[count] == row[0][i + 2]))
		return (0);
	while (str[count] && (str[count] == row[0][i + 1]
		|| str[count] == row[0][i + 2]))
		count++;
	if (str[count])
		return (0);
	return (count);
}

int	is_empty_char(char **row, char vide)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (row[i])
	{
		y = 0;
		while (row[i][y])
		{
			if (row[i][y] == vide)
				return (1);
			y++;
		}
		i++;
	}
	printf("test");
	return (0);
}

int	ft_validate_map(char **row)
{
	int		i;
	int		lenght;
	char	vide;

	i = 1;
	vide = row[0][ft_len(row[0]) - 3];
	if (!row[i] || count_row(row) != check_first_line(row)
		|| check_first_line(row) == 0)
		return (0);
	lenght = is_valid_line(row[i], row);
	while (row[i])
	{
		if (is_valid_line(row[i], row) == 0
			|| is_valid_line(row[i], row) != lenght)
			return (0);
		i++;
	}
	return (is_empty_char(row, vide));
}
