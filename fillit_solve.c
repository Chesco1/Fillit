/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solve.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:01:36 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 16:01:37 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_legal(int *tetrimino, char *index_field)
{
	if (index_field[tetrimino[0]] == '.' && index_field[tetrimino[1]] == '.' &&
		index_field[tetrimino[2]] == '.' && index_field[tetrimino[3]] == '.')
		return (1);
	return (0);
}

static int		get_legal_pos(int *tetrimino, char *field)
{
	int i;

	i = 0;
	while (field[i] != '\0')
	{
		if (is_legal(tetrimino, &field[i]) == 1)
			return (i);
		i++;
	}
	return (-1);
}


static int		is_done(int **tet_array)
{
	int i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][6] != 1)
			return (0);
		i++;
	}
	return (1);	
}

static int		solve(int **tet_array, char *field)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (is_done(tet_array) == 1) 
		return (1);
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][6] == 1)
		{
			i++;
			continue ;
		}
		j = get_legal_pos(tet_array[i], field);
		if (j == -1)
			return (0);
		place_tetrimino(tet_array[i], &field[j]);
		if (solve(tet_array, field) == 1)
			return (1);
		remove_tetrimino(tet_array[i], &field[j]);
		i++;
	}
	return (0);
}

int				fillit_solve(int **tet_array, int tet_amount)
{
	char 	*field;
	int		i;

	i = 0;
	field = make_field(tet_amount);
	while (solve(tet_array, field) != 1)
	{
		expand_field(field, ft_linelen(field), tet_array);
	}
	ft_putstr(field);
	return (0);
}