/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_rile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:03:24 by kbaridon          #+#    #+#             */
/*   Updated: 2024/09/03 18:03:26 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_file_size(char *fileName);
char	**ft_split(char *str, char *charset);

// return all lines in the file
// NULL pointer if it fails to open or read
char	**ft_read_file(char *fileName, char ***ret)
{
	int		fd;
	int		bytes_read;
	int		file_size;
	char	*buffer;

	file_size = ft_file_size(fileName);
	buffer = malloc(file_size);
	if (!buffer)
		return (NULL);
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, buffer, file_size - 1);
	buffer[bytes_read] = '\0';
	close(fd);
	*ret = ft_split(buffer, "\n");
	free(buffer);
	return (*ret);
}

// return the size (nb of characters) of the file
int	ft_file_size(char *fileName)
{
	int		fd;
	int		bytes_read;
	int		total_size;
	char	buffer[250];

	total_size = 0;
	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		return (-1);
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		total_size += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	return (total_size);
}
