/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_valid.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 11:48:17 by ccoers        #+#    #+#                 */
/*   Updated: 2019/03/23 01:01:29 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_linelen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int     ft_strcmp_ignore_newline(const char *s1, const char *s2)
{
    size_t          i;
    char            *str;
    char            *str2;
    size_t          j;

    str = (char *)s1;
    str2 = (char *)s2;
    i = 0;
    j = 0;
    while ((str[i] == str2[j] && str[i] != '\0') || str2[j] == '\n')
    {
        if (str2[j] == '\n')
        {
            j++;
            continue ;
        }
        i++;
        j++;
    }
    return (str[i] - str2[j]);
}

int     ft_strequ_in(char const *s1, char const *s2, int **array)
{
	static int i = 0;

    if (s1 == 0 || s2 == 0)
        return (0);
    if (ft_strcmp_ignore_newline(s1, s2) == 0)
	{
		array[i] = index_n_char((char *)s1, '#', 6);
		array[i][5] = 65 + i;
		array[i][6] = 0;
		i++;
        return (1);
	}
    return (0);
}

int     is_tetrimino2(char *str, char *str2)
{
    //stuk van is_tetrimino, want 26 lines
    return (0);
}

int     is_tetrimino(char *str, int len, int **array)
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

int		check_tetriminos(char *str, int **array)
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

int		input_is_valid4(char *input)
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
		if ((i + 1) % 21 == 0)
		{
			if (pounds != ((i + 1) / 21) * 4 && newlines != ((i + 1) / 21) * 4)
				return (0);
		}
		i++;
	}
	if (pounds != ((i + 1) / 21) * 4 && newlines + 1 != ((i + 1) / 21) * 4)
		return (0);
	return (1);
}

int		input_is_valid3(char *input)
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

int		input_is_valid2(char *input)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int 	strlen;

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

int		input_is_valid1(char *input)
{
	unsigned int	i;

	i = 0;
	if (ft_strlen(input) > 546)
		return (0);
	while (input[i] != '\0')
	{
		if ((i + 1) % 21 == 0)
		{
			if (input[i] != '\n')
				return (0);
		}
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (0);
	return (1);
}

int		input_is_valid(char *input, int **array)
{
	char	*str;
	int		i;

	if (input_is_valid1(input) == 0)
	{
		ft_putendl("hoi1");
		return (0);
	}
	if (input_is_valid2(input) == 0)
    {
        ft_putendl("hoi2");
        return (0);
    }
	if (input_is_valid3(input) == 0)
    {
        ft_putendl("hoi3");
        return (0);
    }
	if (input_is_valid4(input) == 0)
    {
        ft_putendl("hoi4");
        return (0);
    }
	if (check_tetriminos(input, array) == 0)
	{
		ft_putendl("hoi5");
		return (0);
	}
	return (1);
}

char	*get_input(int fd)
{
	char	buf[548];
	char 	*input;
	int 	ret;
	
	ret = read(fd, buf, 548);
	buf[ret] = '\0';
	input = ft_strnew(ft_strlen(buf) + 1);
	ft_strcpy(input, buf);
	return (input);
}

void	adjust_tets(int **array)
{
	int i;
	int j;
	int k;

	i = 0;
	while (array[i] != NULL)
	{
		j = 0;
		while (array[i][j + 1] != -1)
		{
			if (array[i][j + 1] - array[i][j] != 1)
			{
				k = j + 1;
				while (array[i][k] != -1)
				{
					array[i][k]++;
					k++;
				}
			}
			j++;
		}
		i++;
	}
}

void	expand_field(char *field, int linelen, int **array)
{
	int i;
	int j;

	linelen++;
	j = 1;
	i = linelen;
	ft_memset(field, '.', (linelen + 1) * linelen);
	while (j < linelen)
	{
		field[i] = '\n';
		i = i + (linelen + 1);
		j++;
	}
	field[i] = '\0';
	adjust_tets(array);
}
	
char	*make_field(int tet_amount)
{
	char	*field;
	int i;

	i = 0;
	field = ft_strnew(400);
	ft_memset(field, '.', 11);
	field[3] = '\n';
	field[7] = '\n';
	field[11] = '\0';
	return (field);
}

int		is_legal(int *tetrimino, char *index_field)
{
	if (index_field[tetrimino[0]] == '.' && index_field[tetrimino[1]] == '.' &&
		index_field[tetrimino[2]] == '.' && index_field[tetrimino[3]] == '.')
		return (1);
	return (0);
}

int		find_legal_position(int *tetrimino, char *field)
{
	int i;

	i = 0;
	while (field[i] != '\0')
	{
		if (is_legal(tetrimino, &field[i]) == 1)
			return(i);
		i++;
	}
	return (-1);
}

void	remove_tetrimino(int *tetrimino, char *index_field)
{
	int i;

    i = 0;
    while (tetrimino[i] != -1)
    {
        index_field[tetrimino[i]] = '.';
        i++;
    }
	tetrimino[6] = 0;
}

void	place_tetrimino(int *tetrimino, char *index_field)
{
	int i;

	i = 0;
	while (tetrimino[i] != -1)
	{
		index_field[tetrimino[i]] = tetrimino[5];
		i++;
	}
	tetrimino[6] = 1;
}	

int		is_done(int **tet_array)
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

int		ft_solve2(int **tet_array, char *field)
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
		j = find_legal_position(tet_array[i], field);
		if (j == -1)
			return (0);
		place_tetrimino(tet_array[i], &field[j]);
		if (ft_solve2(tet_array, field) == 1)
			return (1);
		remove_tetrimino(tet_array[i], &field[j]);
		i++;
	}
	return (0);
}

int		ft_solve(int **tet_array, int tet_amount)
{
	char 	*field;
	int		i;

	i = 0;
	field = make_field(tet_amount);
	while (ft_solve2(tet_array, field) != 1)
	{
		expand_field(field, ft_linelen(field), tet_array);
	}
	ft_putstr(field);
	return (0);
}

int		main(int argc, char **argv)
{
	int 	fd;
	char	*input;
	int		**tet_array;
	int		tet_amount;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		input = get_input(fd);
		tet_amount = (ft_strlen(input) + 1) / 21;
		tet_array = (int **)malloc(sizeof(int *) * (tet_amount + 1));
		if (fd == -1)
		{
			ft_putendl("error opening file");
			return (0);
		}		
		if (input_is_valid(input, tet_array) == 1)
		{
			tet_array[tet_amount] = NULL;
//			ft_putendl("valid input");
			ft_solve(tet_array, tet_amount);
		}
		else
			ft_putendl("error"); 
	}
	else
		ft_putendl("something something usage");
	return (0);
}
