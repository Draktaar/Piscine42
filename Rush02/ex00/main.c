/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mseverin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:36:15 by mseverin          #+#    #+#             */
/*   Updated: 2024/09/01 19:08:34 by bduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_helper.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
	i++;
	}
	free(str);
}

int	check_argument(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

char	*choice_argument(int argc, char **argv, char ***dictionnaire)
{
	char	*argument;

	if (argc == 2)
	{
		*dictionnaire = init_dict("./numbers.dict");
		argument = clean_arg(argv[1]);
	}
	else if (argc == 3)
	{
		*dictionnaire = init_dict(argv[1]);
		argument = clean_arg(argv[2]);
		if (!*dictionnaire)
			return (NULL);
	}
	else
		return (NULL);
	return (argument);
}

int	main(int argc, char **argv)
{
	char	*argument;
	char	**dictionnaire;

	argument = choice_argument(argc, argv, &dictionnaire);
	if (!argument || !dictionnaire)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_argument(argument))
	{
		write(2, "Error\n", 6);
		ft_free(dictionnaire);
		return (0);
	}
	ft_digit(argument, dictionnaire);
	ft_free(dictionnaire);
	return (0);
}
