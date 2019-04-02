/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit_solve.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:01:36 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/02 04:38:25 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_legal(int **tet_array, const int i, const char *field, const int j)
{
	int *tetrimino;

	tetrimino = tet_array[i];
	if (field[j + tetrimino[1]] == '.' &&
		field[j + tetrimino[2]] == '.' && field[j + tetrimino[3]] == '.')
		return (1);
	return (0);
}

static int		find_legal_pos(int ** tet_array, const int i, char *field, int strlen)
{
	int j;

	j = 0;
	while (field[j] != '\0')
	{
		while (field[j] != '.' && j < strlen)
			j++;
		if (is_legal(tet_array, i, field, j) == 1)
			return (j);
		j++;
	}
	return (-1);
}

static int		is_done(int **tet_array)
{
	int	i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][7] == -1)
			return (0);
		i++;
	}
	return (1);
}

static int		initial_solve(int **tet_array, char *field, int i, const int strlen)
{
	int j;
	static int b;

	if (b >= 700000)
	{
		ft_putendl(field);
		ft_putchar('\n');
		b = 0;
	}
	b++;
	if (is_done(tet_array) == 1)
        return (1);
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][7] != -1)
		{
			i++;
			continue ;
		}
		if (tet_array[i][6] != -1)
		{
			if (tet_array[tet_array[i][6]][7] == -1)
			{
				i++;
				continue ;
			}
		}
		j = find_legal_pos(tet_array, i, field, strlen); // kan sneller door is_valid aan te passen
		if (j == -1)
			return (0);
		place_tetrimino(tet_array[i], &field[j]);
		tet_array[i][7] = j;
		if (was_bad_move(tet_array, i, field, strlen) == 0)
		{
			if (initial_solve(tet_array, field, 0, strlen) == 1)
				return (1);
		}
		remove_tetrimino(tet_array[i], &field[j]);
		i++;
	}
	return (0);
}

static int		solve(int **tet_array, char *field, int i, int strlen)
{
	int	j;
		static int k;

		if (k >= 4)
		{
			ft_putstr(field);
			ft_putendl("\n");
			k = 0;
	}
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
		if (is_legal(tet_array, i, field, j) == 1)
	    {
			place_tetrimino(tet_array[i], &field[j]);
			k++;
//			ft_putendl(field);
//			ft_putstr("\n");
			tet_array[i][7] = j;
			if (was_bad_move(tet_array, i, field, 0) == 0)
			{
			  if (solve(tet_array, field, i + 1, strlen) == 1)
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

int				fillit_solve(int **tet_array, const int tet_amount)
{
	char	*field;
	int		i;
	int 	strlen;
	
	i = 0;
	field = make_field(tet_amount, tet_array, 0);
	strlen = ft_strlen(field);
	while (initial_solve(tet_array, field, 0, strlen) != 1)
	{
		expand_field(field, ft_linelen(field), tet_array);
		strlen = ft_strlen(field);
	}
	ft_putendl(field);
	ft_putchar('\n');
	clean_field(field);
	convert_tets(tet_array);
	while (solve(tet_array, field, 0, strlen) != 1)
    {
		expand_field(field, ft_linelen(field), tet_array);
		strlen = ft_strlen(field);
    }
//	solve(tet_array, field, 0, strlen);
	ft_putendl(field);
	return (0);
}
