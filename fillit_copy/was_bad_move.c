/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   was_bad_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:54:34 by ccoers        #+#    #+#                 */
/*   Updated: 2019/03/29 23:53:03 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int count_dots(char *field, int *tetrimino)
{
	int i;
	int dots;

	i = 0;
	dots = 0;
	while (i < (tetrimino[7] + 1) && field[i] != '\0')
	{
		if (field[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}

int 	was_bad_move(int **tet_array, int tet_index_at_call, char *field)
{
	int i;
	int j;
	int dots;
//	static int b;

//	if (b >= 50)
//		exit(1);
	j = 0;
	dots = count_dots(field, tet_array[tet_index_at_call]);
//	i = 0;
	i = tet_index_at_call + 1;
//	b++;
//	ft_putendl(field);
//	ft_putstr("\n");
	if (ft_linelen(field) != 9)
		return (0);
	if (dots > 1)
	{
//		while (dots_to_check > 0)
//		{
			while (field[j] != '.' && field[j] != '\0')
				j++;
			while (tet_array[i] != NULL)
			{
				if (is_legal(tet_array, i, field, j) == 1)
				{
					place_tetrimino(tet_array[i], &field[j]);
//					ft_putendl(field);
//					ft_putendl("");
					if (was_bad_move(tet_array, tet_index_at_call, field) == 0)
					{
						remove_tetrimino(tet_array[i], &field[j]);
						return (0);
					}
					remove_tetrimino(tet_array[i], &field[j]);
					//		return (1);
				}
				i++;
			}
			return (1);
//			dots_to_check--;
//			j++;
//		}
//		return (1);
	}
	return (0);
}
