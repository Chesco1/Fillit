/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_tetriminos.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:32:51 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 16:33:19 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_tetrimino2(char *str, char *str2)
{
	//stuk van is_tetrimino, want 26 lines
	return (0);
}

static int	is_tetrimino(char *str, int len, int **array)
{
	char 			*str2;
	unsigned int	i;

	i = ft_strchr_int(str, '#');
	str2 = ft_strsub(str, i, len - i);
	if ((ft_strequ_in(T1, str2, array) == 1 && i % 5 == 0) ||
		ft_strequ_in(T2, str2, array) == 1 ||
		(ft_strequ_in(T3, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T4, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T5, str2, array) == 1 && (i + 2) % 5 != 0 && (i + 3) % 5 != 0) ||
		(ft_strequ_in(T6, str2, array) == 1 && i % 5 != 0 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T7, str2, array) == 1 && i % 5 != 0) ||
		(ft_strequ_in(T8, str2, array) == 1 && (i + 2) % 5 != 0 && (i + 3) % 5 != 0) ||
		(ft_strequ_in(T9, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T10, str2, array) == 1 && (i + 2) % 5 != 0 && (i + 3) % 5 != 0) ||
		(ft_strequ_in(T11, str2, array) == 1 && i % 5 != 0) ||
		(ft_strequ_in(T12, str2, array) == 1 && i % 5 != 0 && (i - 1) % 5 != 0) ||
		(ft_strequ_in(T13, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T14, str2, array) == 1 && (i + 2) % 5 != 0 && (i + 3) % 5 != 0) ||
		(ft_strequ_in(T15, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T16, str2, array) == 1 && i % 5 != 0 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T17, str2, array) == 1 && (i + 2) % 5 != 0) ||
		(ft_strequ_in(T18, str2, array) == 1 && (i + 2) % 5 != 0 && (i + 3) % 5 != 0) ||
		(ft_strequ_in(T19, str2, array) == 1 && i % 5 != 0))
		return (1);
	return (0);
}

int			check_tetriminos(char *str, int **array)
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
		if (is_tetrimino(&str[i], (k - i) + 1, array) == 0)
			return (0);
		i = i + 21;
	}
	return (1);
}
