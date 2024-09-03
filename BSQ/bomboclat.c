/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomboclat.c                                        :+:      :+:    :+:   */
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

void pritn(char **board)
{
    int i;
    int j;

    i = 0;
    while (board[i] != 0)
    {
        j = 0;
        while (board[i][j] != '\0')
        {
            printf("%c ", board[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

typedef struct s_square
{
    int x;
    int y;
    int size;
} t_square;




int ft_check_square(char **board, t_square square)
{
    int row;
    int col;

    row = 0;
    while (row < square.size)
    {
        col = 0;
        while (col < square.size)
        {
            if (board[square.y + row + 1][square.x +col + 1] != '.')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}

void ft_solve(char **board, t_square square, int x, int y)
{
    if (y + square.size > 8)
    {
        int row;
        int col;

        row = 0;
        while (row < square.size)
        {
            col = 0;
            while (col < square.size)
            {
                board[row][col] = 'x';
                col++;
            }
            row++;
        }
    }
    else if (x + square.size > 27)
        return (ft_solve(board,square, 0, y + 1));
    while (ft_check_square(board, square))
    {
        square.x = x;
        square.y = y;
        square.size += 1;
    }
    return (ft_solve(board,square, x + 1, y));
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void ft_test(char **board, t_square square)
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < ft_strlen(board[i]))
        {
            if (ft_check_square(board, square))
            {
                square.x = j;
                square.y = i;
                while (ft_check_square(board, square))
                {
                    square.size += 1;
                }
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    char str[] = "...........................\n....o......................\n............o..............\n...........................\n....o......................\n...............o...........\n...........................\n......o..............o.....\n..o.......o................\n";
    
    char **board;
    board = ft_split(str, "\n");

    t_square square;
    square.x = 0;
    square.y = 0;
    square.size = 0;

    ft_solve(board, square, 0,0);
    pritn(board);
}