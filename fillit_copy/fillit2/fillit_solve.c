/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solve.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:01:36 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 00:42:07 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_legal(int *tetrimino, char *index_field)
{
	if (index_field[tetrimino[1]] == '.' &&
		index_field[tetrimino[2]] == '.' && index_field[tetrimino[3]] == '.')
		return (1);
	return (0);
}

static int		find_legal_pos(int *tetrimino, char *field)
{
	int i;

	i = 0;
	while (field[i] != '\0')
	{
		while (field[i] != '.' && field[i] != '\0')
			i++;
		if (is_legal(tetrimino, &field[i]) == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int		is_done(int **tet_array)
{
	int	i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][7] != 1)
			return (0);
		i++;
	}
	return (1);
}

static int		initial_solve(int **tet_array, char *field, int i, int j)
{
	static int k;

	if (k == 1000000)
	{
		ft_putstr(field);
		ft_putendl("\n");
		k = 0;
	}
	if (is_done(tet_array) == 1)
        return (1);
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][7] == 1)
		{
			i++;
			continue ;
		}
		if (tet_array[i][6] != -1)
		{
			if (tet_array[tet_array[i][6]][7] == 0)
			{
				i++;
				continue ;
			}
		}
		j = find_legal_pos(tet_array[i], field);
		if (j == -1)
			return (0);
		place_tetrimino1(tet_array[i], &field[j]);
		k++;
		if (initial_solve(tet_array, field, 0, 0) == 1)
			return (1);
		remove_tetrimino1(tet_array[i], &field[j]);
		i++;
	}
	return (0);
}

static int		final_solve(int **tet_array, char *field, int i, int j)
{
	if (tet_array[i] == NULL)
        return (1);
	j = tet_array[tet_array[i][6]][7] + 1;
	j = 0;
	while (field[j] != '\0')
	{
		
		while (field[j] != '.' && field[j] != '\0')
			j++;
		if (is_legal(tet_array[i], &field[j]) == 1)
	    {
			place_tetrimino2(tet_array[i], &field[j]);
			tet_array[i][7] = j;
			if (final_solve(tet_array, field, i + 1, 0) == 1)
				return (1);
			remove_tetrimino2(tet_array[i], &field[j]);
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
	while (initial_solve(tet_array, field, 0, 0) != 1)
	{
	  expand_field(field, ft_linelen(field), tet_array);
	}
	clean_field(field);
	convert_tets(tet_array);
	final_solve(tet_array, field, 0, 0);
	ft_putstr(field);
	return (0);
}
