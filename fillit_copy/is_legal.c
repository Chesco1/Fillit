/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_legal.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 13:16:52 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/17 13:30:15 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     is_legal(int **tet_array, const int i, const unsigned char *field,
		const int j)
{
	int *tetrimino;

    tetrimino = tet_array[i];
    if (tetrimino[6] != -1)
    {
		if (j <= tet_array[tetrimino[6]][7] || (tet_array[tetrimino[6]][7] == -1))
			return (0);
    }
    if (field[j + tetrimino[1]] == '.' &&
        field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
        return (1);
    return (0);
}

int     is_legal2(int **tet_array, const int i, const unsigned char *field,
		const int j)
{
    int *tetrimino;

    tetrimino = tet_array[i];
    if (tetrimino[6] != -1)
    {
        if (j <= tet_array[tetrimino[6]][7])
            return (0);
    }
    if (field[j + tetrimino[1]] == '.' &&
        field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
        return (1);
    return (0);
}
