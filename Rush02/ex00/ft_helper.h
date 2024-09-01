/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:50:50 by achu              #+#    #+#             */
/*   Updated: 2024/09/01 15:53:51 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
# define FT_HELPER_H

char	**ft_split(char *str, char *charset);
char	**init_dict(char *path);
char	*clean_arg(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_clean_dict(char **tab);
void	ft_digit(char *str, char **dictionnaire);
int		ft_arraylen(char *str);

#endif
