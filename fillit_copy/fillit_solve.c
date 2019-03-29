/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solve.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:01:36 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/30 00:02:36 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_legal(int **tet_array, int i, char *field, int j)
{
	int *tetrimino;

	tetrimino = tet_array[i];
	if (j <= tet_array[tetrimino[6]][7] || tetrimino[8] == 1)
		return(0);
	if (field[j + tetrimino[1]] == '.' &&
		field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
		return (1);
	return (0);
}

static int		solve(int **tet_array, char *field, int i)
{
	int	j;
//	static int k;

//	if (k >= 100000)
//	{
//		ft_putstr(field);
//		ft_putendl("\n");
//		k = 0;
//	}
	if (tet_array[i] == NULL)
        return (1);
	j = tet_array[tet_array[i][6]][7] + 1;
	while (field[j] != '\0')
	{
		while (field[j] != '.' && field[j] != '\0')
			j++;
		if (is_legal(tet_array, i, field, j) == 1)
	    {
			place_tetrimino(tet_array[i], &field[j]);
//			k++;
//			ft_putendl(field);
//			ft_putstr("\n");
			tet_array[i][7] = j;
			if (was_bad_move(tet_array, i, field) == 0)
			{
				if (solve(tet_array, field, i + 1) == 1)
					return (1);
			}
			remove_tetrimino(tet_array[i], &field[j]);
//			if (k >= 10)
//			{
//				ft_putstr(field);
//				ft_putendl("\n");
//				k = 0;
//			}
	    }
	  j++;
	}
	return (0);
}

int				fillit_solve(int **tet_array, int tet_amount)
{
	char	*field;
	int		i;

	i = 0;
	field = make_field(tet_amount, tet_array, 0);
	while (solve(tet_array, field, 0) != 1)
	{
	  expand_field(field, ft_linelen(field), tet_array);
	}
	ft_putstr(field);
	return (0);
}
