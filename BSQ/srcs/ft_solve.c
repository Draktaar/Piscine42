/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:00:04 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/04 20:00:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.h"
#include "../includes/ft_solvemap.h"

void	ft_solve(char **row, t_square square)
{
	t_map	map_data;

	if (ft_validate_map(row) == 0)
	{
		write(2, "map error\n", 10);
		free_row(row);
	}
	else
	{
		map_data = ft_init_map(row);
		ft_resolve(map_data, &square);
		ft_draw_map(map_data, square);
		ft_print_map(map_data);
		free_row(row);
	}
}
