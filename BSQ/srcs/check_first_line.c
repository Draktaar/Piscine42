/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:46:14 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/04 17:46:20 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	check_first_line(char **row)
{
	int		i;
	int		nb_col;
	char	temp[100];

	i = 0;
	if (ft_len(row[0]) > 4)
	{
		while (row[0][i] >= '0' && row[0][i] <= '9' && row[0][i + 3] != '\0')
		{
			temp[i] = row[0][i];
			i++;
		}
		temp[i] = '\0';
		nb_col = ft_atoi(temp);
	}
	else
		nb_col = row[0][0] - '0';
	if (check_first_line2(row, i) == 0)
		return (0);
	return (nb_col);
}

int	check_first_line2(char **row, int i)
{
	int	y;

	while (row[0][i])
	{
		if (row[0][i] < ' ' || row[0][i] > 126)
			return (0);
		y = i + 1;
		while (row[0][y])
		{
			if (row[0][i] == row[0][y])
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}
