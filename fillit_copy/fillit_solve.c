/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solve.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:01:36 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/19 16:06:33 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_legal_pos(int **tet_array, const int i,
		unsigned char *field, const int strlen)
{
	int		j;
	int		dots;
	int		max_dots;

	j = 0;
	max_dots = field[170];
	dots = 0;
	if (tet_array[i][7] != -1)
		return (-2);
	while (dots <= max_dots && j < strlen)
	{
		while (field[j] != '.' && j < strlen)
			j++;
		if (is_legal(tet_array, i, field, j) == 1)
			return (j);
		j++;
		dots++;
	}
	if (dots > max_dots)
		return (-2);
	return (-1);
}

static int	is_done(int **tet_array)
{
	int		i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][7] == -1)
			return (0);
		i++;
	}
	return (1);
}

static int	initial_solve(int **tet_array, unsigned char *field, int i,
		const int strlen)
{
	int		j;

	if (is_done(tet_array) == 1)
		return (1);
	while (tet_array[i] != NULL)
	{
		while (tet_array[i + 1] != NULL && tet_array[i][7] != -1)
			i++;
		j = find_legal_pos(tet_array, i, field, strlen);
		if (j == -2)
		{
			i++;
			continue ;
		}
		else if (j == -1)
			return (0);
		place_tetrimino(tet_array[i], &field[j], j);
		tet_array[i][7] = j;
		if (initial_solve(tet_array, field, 0, strlen) == 1)
			return (1);
		remove_tetrimino(tet_array[i], &field[j]);
		i++;
	}
	return (0);
}

static int	final_solve(int **tet_array, unsigned char *field, int i,
		int strlen)
{
	int	j;

	if (tet_array[i] == NULL)
		return (1);
	if (tet_array[i][6] != -1)
		j = tet_array[tet_array[i][6]][7] + 1;
	else
		j = 0;
	while (field[j] != '\0')
	{
		while (field[j] != '.' && j < strlen)
			j++;
		if (is_legal2(tet_array, i, field, j) == 1)
		{
			place_tetrimino(tet_array[i], &field[j], j);
			if (was_bad_move(tet_array, i, field, strlen) == 0)
			{
				if (final_solve(tet_array, field, i + 1, strlen) == 1)
					return (1);
			}
			remove_tetrimino(tet_array[i], &field[j]);
		}
		j++;
	}
	return (0);
}

int			fillit_solve(int **tet_array, const int tet_amount)
{
	unsigned char	*field;
	int				i;
	int				strlen;

	i = 0;
	field = make_field(tet_amount, tet_array, 0);
	strlen = (unsigned char)ft_strlen((char *)field);
	field[171] = strlen;
	one_square_check(tet_array);
	while (initial_solve(tet_array, field, i, strlen) != 1)
	{
		expand_field(field, ft_linelen((char *)field), tet_array);
		strlen = ft_strlen((char *)field);
	}
	clean_field(field, tet_array);
	final_solve(tet_array, field, 0, strlen);
	ft_putendl((char *)field);
	return (0);
}
