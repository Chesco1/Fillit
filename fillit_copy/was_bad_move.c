/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   was_bad_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:54:34 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/11 15:37:59 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int             is_legal2(int **tet_array, const int i, const unsigned char *field, const int j)
{
    int *tetrimino;

    tetrimino = tet_array[i];
    	if (tetrimino[7] != -1)
		return(0);
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


static int count_dots2(const unsigned char *field, const int *tetrimino)
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

int count_dots1(const unsigned char *field, const int j)
{
        int i;
        int dots;

        i = 0;
        dots = 0;
        while (i <= j - 1)
        {
                if (field[i] == '.')
                        dots++;
                i++;
        }
        return (dots);
}

static int     was_bad_move3(int **tet_array, const int tet_index_at_call, unsigned char *field, int *j)
{
	int i;
	int strlen;

	strlen = field[171];
	while (field[*j] != '.' && *j < strlen)
		(*j)++;
	i = tet_index_at_call + 1;
	while (tet_array[i] != NULL)
	{
		if (is_legal2(tet_array, i, field, *j) == 1)
		{
			place_tetrimino(tet_array[i], &field[*j], *j);
			if (was_bad_move2(tet_array, tet_index_at_call, field, strlen) == 0)
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

int     was_bad_move2(int **tet_array, const int tet_index_at_call, unsigned char *field, const int strlen)
{
	int i;
	int j;
	int loops;
	int dots;
	int max_dots;

	j = 0;
	dots = count_dots2(field, tet_array[tet_index_at_call]);
	loops = 0;
	max_dots = field[170];                                                           
	if (dots > max_dots)
	{
		while (loops <= max_dots)
		{
/*			while (field[j] != '.' && j < strlen)
				j++;
			i = tet_index_at_call + 1;
			while (tet_array[i] != NULL)
			{
				if (is_legal2(tet_array, i, field, j) == 1)
				{
					place_tetrimino(tet_array[i], &field[j], j);
					if (was_bad_move2(tet_array, tet_index_at_call, field, strlen) == 0)
					{
						remove_tetrimino(tet_array[i], &field[j]);
						return (0);
					}
					remove_tetrimino(tet_array[i], &field[j]);
				}
				i++;
				}  */
			if (was_bad_move3(tet_array, tet_index_at_call, field, &j) == 0)
				return (0);
			loops++;
			j++;
		}
		return (1);
	}
	return (0);
}

int 	was_bad_move1(unsigned char *field, int j)
{
	int dots;
	int max_dots;

	max_dots = field[170];
	dots = count_dots1(field, j);
	if (dots > max_dots)
		return (1);
	return (0);
}
