/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_tetriminos.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:32:51 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/22 19:34:52 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_tetrimino2(char *str2, int **tet_array, int i)
{
	if ((ft_strequ_ignore_nl(T11, str2, tet_array) == 1 && i % 5 != 0) ||
		(ft_strequ_ignore_nl(T12, str2, tet_array) == 1 && i % 5 != 0 &&
		(i - 1) % 5 != 0) ||
		(ft_strequ_ignore_nl(T13, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T14, str2, tet_array) == 1 && (i + 2) % 5 != 0 &&
		(i + 3) % 5 != 0) ||
		(ft_strequ_ignore_nl(T15, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T16, str2, tet_array) == 1 && i % 5 != 0 &&
		(i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T17, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T18, str2, tet_array) == 1 && (i + 2) % 5 != 0 &&
		(i + 3) % 5 != 0) ||
		(ft_strequ_ignore_nl(T19, str2, tet_array) == 1 && i % 5 != 0))
		return (1);
	return (0);
}

static int	is_tetrimino(char *str, int len, int **tet_array)
{
	char			*str2;
	unsigned int	i;

	i = ft_strchr_int(str, '#');
	str2 = ft_strsub(str, i, len - i);
	if ((ft_strequ_ignore_nl(T1, str2, tet_array) == 1 && i % 5 == 0) ||
		ft_strequ_ignore_nl(T2, str2, tet_array) == 1 ||
		(ft_strequ_ignore_nl(T3, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T4, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T5, str2, tet_array) == 1 && (i + 2) % 5 != 0 &&
		(i + 3) % 5 != 0) ||
		(ft_strequ_ignore_nl(T6, str2, tet_array) == 1 && i % 5 != 0 &&
		(i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T7, str2, tet_array) == 1 && i % 5 != 0) ||
		(ft_strequ_ignore_nl(T8, str2, tet_array) == 1 && (i + 2) % 5 != 0 &&
		(i + 3) % 5 != 0) ||
		(ft_strequ_ignore_nl(T9, str2, tet_array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_ignore_nl(T10, str2, tet_array) == 1 && (i + 2) % 5 != 0 &&
		(i + 3) % 5 != 0))
		return (1);
	return (is_tetrimino2(str2, tet_array, i));
}

int			check_tetriminos(char *str, int **tet_array)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	while (str[i] != '\0')
	{
		k = i;
		j = 0;
		while (j < 4)
		{
			if (str[k] == '#' && j > 0)
				k++;
			while (str[k] != '#')
				k++;
			j++;
		}
		if (is_tetrimino(&str[i], (k - i) + 1, tet_array) == 0)
			return (0);
		i = i + 21;
	}
	return (1);
}
