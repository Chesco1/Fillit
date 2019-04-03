/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   was_bad_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 11:54:34 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/02 21:46:10 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int             is_legal2(int **tet_array, const int i, const char *field, const int j)
{
    int *tetrimino;

    tetrimino = tet_array[i];
	if (tetrimino[7] != -1)
		return(0);
	if (tetrimino[6] != -1)
	  {
	   if (j < tet_array[tetrimino[6]][7] || (tet_array[tetrimino[6]][7] == -1))
	      return (0);
	  }
      if (field[j + tetrimino[1]] == '.' &&
		  field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
		  return (1);
      return (0);
}


static int count_dots2(const char *field, const int *tetrimino)
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

static int count_dots1(const char *field, const int j)
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

int     was_bad_move2(int **tet_array, const int tet_index_at_call, char *field, int j)
{
        int i;
        int dots;
        int strlen;
        int max_dots;
	static int loops;
	static int b;

        dots = count_dots2(field, tet_array[tet_index_at_call]);
	if (b >= 2000000)
	{
                   ft_putendl(field);                                            
                   ft_putchar('\n');
		   ft_putnbr(dots);
	b = 0;
	}
	b++;
        //      loops = field[172];                                                
        strlen = field[171];
        max_dots = field[170];
        //      j = ft_memchr_int(field, '.', strlen - j);                         
        //      j = 0;                                                             
        if (dots > max_dots)
        {
                while (loops <= max_dots)
                {
		  //loops++;
                 	while (field[j] != '.' && j < strlen)
                                j++;
                        //                     j = j + ft_memchr_int(&field[j], '.', strlen - j);
                        i = tet_index_at_call + 1;
                        while (tet_array[i] != NULL)
                        {
			  loops++;
                                if (is_legal2(tet_array, i, field, j) == 1)
                                {
                                        place_tetrimino(tet_array[i], &field[j]);
                                        tet_array[i][7] = j;
                                        if (was_bad_move2(tet_array, tet_index_at_call, field, 0) == 0)
                                        {
                                                remove_tetrimino(tet_array[i], &field[j]);
                                                return (0);
                                        }
                                        remove_tetrimino(tet_array[i], &field[j]);
                                }
                                i++;
                        }                                      
                        j++;
			//loops++;
                }
		//	loops = 0;
                return (1);
        }
	loops = 0;
        return (0);
}

int 	was_bad_move1(char *field, int j)
{
	int dots;
	int max_dots;
	//    	static int b;
	//
	//	if (b >= 2000000)
	//  {
	    //	     ft_putendl(field);
	    //	     ft_putchar('\n');
	//     b = 0;
	//	  }
	//b++;
	max_dots = field[170];
	dots = count_dots1(field, j);
	if (dots > max_dots)
		return (1);
	return (0);
}
