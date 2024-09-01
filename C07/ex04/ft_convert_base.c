/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:09:03 by achu              #+#    #+#             */
/*   Updated: 2024/08/29 19:09:07 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char base_dec[] = "0123456789";

int ft_strlen(char *str);
int ft_nbrlen(int nbr, int div);
int	ft_power(int nbr, int power);
int ft_index_base(char c, char *base);

int ft_convert_dec_base(char *nbr, char *base)
{
    int i;
    int len;
    int sum;

    i = 0;
    len = ft_strlen(nbr) - 1;
    while (i <= len)
    {
        sum += search_base(nbr[i], base) * ft_power(ft_strlen(base), len - i);
        i++;
    }
    return (sum);
}

char *ft_convert_any_base(int nbr, char *base_to)
{
    int i;
    int div;
    int len;
    int temp;
    char *base;

    i = 0;
    div = ft_strlen(base_to);
    len = ft_nblen(nbr, div);
    base = (char *)malloc ((len + 1) * sizeof(char));
    while (0 < nbr)
    {
        temp = nbr % div;
        if (0 <= temp)
            base[len - i - 1] = base_to[temp];
        nbr /= div;
        i++;
    }
    base[i] = '\0';
    return (base);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    char *converted_base;
    converted_base = ft_convert_any_base(ft_convert_dec_base(nbr, base_from), base_to);
    return (converted_base);
}

int main(int argc, char const *argv[])
{
    char *test;
    test = ft_convert_base("213323", "01234", "0123456789ABCDEF");
    printf("%s", test);
    return 0;
}