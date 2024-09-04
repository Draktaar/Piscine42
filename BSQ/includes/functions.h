/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:57:01 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/04 19:47:43 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_solvemap.h"

int		ft_len(char *str);
int		ft_atoi(char *str);
int		count_row(char **row);
int		ft_file_size(char *fileName);
int		ft_validate_map(char **row);
int		check_first_line(char **row);
int		check_first_line2(char **row, int i);
int		is_charset(char *str, char *charset);
int		is_valid_line(char *str, char **row);
int		is_empty_char(char **row, char vide);
int		ft_count_words(char *str, char *charset);
int		strn_cpy(char *dest, char *src, int i, unsigned int n);
char	**ft_read_file(char *fileName, char ***ret);
char	**ft_split(char *str, char *charset);
void	free_row(char **arr);
void	ft_solve(char **row, t_square square);

#endif // FUNCTIONS_H
