/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_is_valid.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 11:48:17 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/22 19:40:35 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		input_is_valid4(char *input)
{
	unsigned int	newlines;
	unsigned int	pounds;
	unsigned int	i;

	i = 0;
	pounds = 0;
	newlines = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '#')
			pounds++;
		else if (input[i] == '\n')
			newlines++;
		if ((i + 1) % SIZE_TET == 0)
		{
			if (pounds != ((i + 1) / SIZE_TET) * 4 &&
				newlines != ((i + 1) / SIZE_TET) * 4)
				return (0);
		}
		i++;
	}
	if (pounds != ((i + 1) / SIZE_TET) * 4 && newlines + 1 !=
		((i + 1) / SIZE_TET) * 4)
		return (0);
	return (1);
}

static int		input_is_valid3(char *input)
{
	unsigned int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '.' && input[i] != '#' && input[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int		input_is_valid2(char *input)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	strlen;

	strlen = ft_strlen(input);
	i = 0;
	while (i <= strlen)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_linelen(&input[i]) != 4)
				return (0);
			i = i + ft_strchr_int(&input[i], '\n') + 1;
			j++;
		}
		if (ft_linelen(&input[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

static int		input_is_valid1(char *input)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(input) > SIZE_TET * MAX_TETS)
		return (0);
	while (input[i] != '\0')
	{
		if ((i + 1) % SIZE_TET == 0)
		{
			if (input[i] != '\n')
				return (0);
		}
		i++;
	}
	if ((i + 1) % SIZE_TET != 0)
		return (0);
	return (1);
}

int				input_is_valid(char *input, int **tet_array)
{
	if (input_is_valid1(input) == 0)
		return (0);
	if (input_is_valid2(input) == 0)
		return (0);
	if (input_is_valid3(input) == 0)
		return (0);
	if (input_is_valid4(input) == 0)
		return (0);
	if (check_tetriminos(input, tet_array) == 0)
		return (0);
	return (1);
}
