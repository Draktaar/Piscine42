/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 10:46:18 by bduval            #+#    #+#             */
/*   Updated: 2024/09/01 18:02:59 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_helper.h"

int	get_dict_size(char *path)
{
	char	*extract_dict;
	int		fd;
	int		read_size;
	int		read_full_size;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 100;
	read_size = i;
	read_full_size = 0;
	while (read_size > 0)
	{
		extract_dict = (char *) malloc(sizeof (char) * i);
		if (!extract_dict)
			return (0);
		read_size = read(fd, extract_dict, i);
		i += 100;
		read_full_size += read_size;
		free(extract_dict);
	}
	close(fd);
	return (read_full_size);
}

char	**init_dict(char *path)
{
	char	**dict;
	char	*extract_dict;
	int		full_size;
	int		fd;

	full_size = get_dict_size(path);
	if (full_size == -1)
		return (NULL);
	fd = open(path, O_RDONLY);
	extract_dict = (char *) malloc(sizeof (char) * full_size);
	if (!extract_dict)
		return (NULL);
	full_size = read(fd, extract_dict, full_size);
	close(fd);
	dict = ft_split(extract_dict, ":\n");
	if (!dict)
		return (NULL);
	ft_clean_dict(dict);
	return (dict);
}
