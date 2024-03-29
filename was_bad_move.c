/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   was_bad_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:54:34 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/23 14:19:42 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		was_bad_move2(int **tet_array, const int tet_index_at_call,
		unsigned char *field, int *j)
{
	int i;
	int strlen;

	strlen = STRLEN;
	while (field[*j] != '.' && *j < strlen)
		(*j)++;
	i = tet_index_at_call + 1;
	while (tet_array[i] != NULL)
	{
		if (is_legal(tet_array, i, field, *j) == 1)
		{
			place_tetrimino(tet_array[i], &field[*j], *j);
			if (was_bad_move(tet_array, tet_index_at_call, field, strlen) == 0)
			{
				remove_tetrimino(tet_array[i], &field[*j]);
				return (0);
			}
			remove_tetrimino(tet_array[i], &field[*j]);
		}
		i++;
	}
	return (1);
}

int		was_bad_move(int **tet_array, const int tet_index_at_call,
		unsigned char *field, const int max_dots)
{
	int j;
	int loops;
	int dots;

	j = 0;
	loops = 0;
	dots = count_dots(field, tet_array[tet_index_at_call]);
	if (dots > max_dots && (max_dots <= 8))
	{
		while (loops <= max_dots)
		{
			if (was_bad_move2(tet_array, tet_index_at_call, field, &j) == 0)
				return (0);
			loops++;
			j++;
		}
		return (1);
	}
	return (0);
}
