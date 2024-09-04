/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:08:36 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/03 18:08:56 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"

int	main(int argc, char **argv)
{
	char		*filename;
	char		**row;
	int			i;
	t_square	square;

	square.x = 0;
	square.y = 0;
	square.size = 0;
	i = 1;
	while (i < argc)
	{
		filename = argv[i];
		row = ft_read_file(filename, &row);
		if (row == NULL)
			write(2, "map error\n", 10);
		else
			ft_solve(row, square);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
}
