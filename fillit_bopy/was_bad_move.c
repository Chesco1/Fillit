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

static int             is_legal2(int **tet_array, const int i, const char *field, const int j)
{
        int *tetrimino;

        tetrimino = tet_array[i];
	if (tetrimino[6] != -1)
	  {
	    if (j <= tet_array[tetrimino[6]][7] || (tet_array[tetrimino[6]][7] == -1))
	      return (0);
	  }
        if (tetrimino[7] != -1)
                return(0);
        if (field[j + tetrimino[1]] == '.' &&
                field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
                return (1);
        return (0);
}


static int count_dots(const char *field, const int *tetrimino)
{
	int i;
	int dots;

	i = 0;
	dots = 0;
	while (i <= (tetrimino[7]) - 1)
	{
		if (field[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}

int 	was_bad_move(int **tet_array, const int tet_index_at_call, char *field, const int strlen)
{
	int i;
	int j;
	int dots;
	int loops;
	int max_dots;
			static int b;
	
		if (b >= 16000000)
		  {
		    ft_putendl(field);
		    ft_putstr("\n");
		    b = 0;
		  }
	max_dots = field[170];
	loops = 0;
	j = 0;
	dots = count_dots(field, tet_array[tet_index_at_call]);
	i = tet_index_at_call + 1;
       	b++;
	if (dots > max_dots)
	{
		while (loops <= max_dots)
	  	{
			while (field[j] != '.' && j < strlen)
				j++;
			while (tet_array[i] != NULL)
			{
				if (is_legal2(tet_array, i, field, j) == 1)
				{
					place_tetrimino(tet_array[i], &field[j]);
					tet_array[i][7] = j;
					if (was_bad_move(tet_array, tet_index_at_call, field, strlen) == 0)
					{
						remove_tetrimino(tet_array[i], &field[j]);
						return (0);
					}
					remove_tetrimino(tet_array[i], &field[j]);
				}
				i++;
			}
			loops++;
			j++;
		}
		return (1);
	}
	return (0);
}
