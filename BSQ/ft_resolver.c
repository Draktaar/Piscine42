/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:12:29 by achu              #+#    #+#             */
/*   Updated: 2024/09/03 18:33:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

typedef struct s_square
{
    int x;
    int y;
    int size;
} t_square;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_print_map(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i] != 0)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            write(1, &map[i][j], 1);
            write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void ft_draw_map(char **map, t_square square)
{
    int row;
    int col;

    row = 0;
    while (row < square.size - 1)
    {
        col = 0;
        while (col < square.size - 1)
        {
            map[square.y + row][square.x + col] = 'x';
            col++;
        }
        row++;
    }
}

int ft_check_square(char **map, t_square square, int x, int y)
{
    int row;
    int col;

    row = 0;
    while (row < square.size)
    {
        col = 0;
        while (col < square.size)
        {
            if (map[y + row][x + col] != '.')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}

void ft_resolve(char **map, t_square *square)
{
    int i;
    int j;

    i = 0;
    while (i + (*square).size < 10)
    {
        j = 0;
        while (j + (*square).size < 26)
        {
            while (ft_check_square(map, (*square), j, i))
            {
                (*square).x = j;
                (*square).y = i;
                (*square).size ++;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    char str[] = "...........................\n....o..o....o..............\n............o..............\n...........................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................\n";
    
    char **map;
    map = ft_split(str, "\n");

    t_square square;
    square.x = 0;
    square.y = 0;
    square.size = 0;

    ft_resolve(map, &square);
    ft_draw_map(map, square);
    ft_print_map(map);
}