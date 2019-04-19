/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   was_bad_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:54:34 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/18 17:15:41 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		was_bad_move2(int **tet_array, const int tet_index_at_call,
		unsigned char *field, int *j)
{
	int i;
	int strlen;

	strlen = field[171];
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
		unsigned char *field, const int strlen)
{
	int j;
	int loops;
	int dots;
	int max_dots;

	j = 0;
	loops = 0;
	dots = count_dots(field, tet_array[tet_index_at_call]);
	max_dots = field[170];
	if (dots > max_dots && (max_dots <= 5 || tet_index_at_call < 12))
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
