/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:11:35 by achu              #+#    #+#             */
/*   Updated: 2024/08/15 11:35:16 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	right = 0;
	while (left <= 98)
	{
		right = left + 1;
		while (right <= 99)
		{	
			ft_putchar(48 + left / 10);
			ft_putchar(48 + left % 10);
			ft_putchar(32);
			ft_putchar(48 + right / 10);
			ft_putchar(48 + right % 10);
			if (left == 98 && right == 99)
				return ;
			ft_putchar(44);
			ft_putchar(32);
			right++;
		}
		left++;
	}
}
