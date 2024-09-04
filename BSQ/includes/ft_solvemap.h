/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solvemap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:51:32 by achu              #+#    #+#             */
/*   Updated: 2024/09/04 19:59:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVEMAP_H
# define FT_SOLVEMAP_H

# include <unistd.h>

typedef struct s_square
{
	int	x;
	int	y;
	int	size;
}	t_square;

typedef struct s_map
{
	char	**map;
	char	blank;
	char	wall;
	char	ink;
}	t_map;

t_map	ft_init_map(char **data);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
void	ft_print_map(t_map mdata);
void	ft_draw_map(t_map mdata, t_square square);
void	ft_resolve(t_map mdata, t_square *square);
int		ft_check_square(t_map mdata, t_square square, int x, int y);

#endif
