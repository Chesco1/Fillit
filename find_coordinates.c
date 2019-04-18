/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_coordinates.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:59:22 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/01 16:59:24 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void					set_y_coordinates(char *str, t_coordinates *result)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (count < 3)
	{
		if (str[i] == '#')
		{
			if (count == 0)
				result->pos1.y = i / 4;
			else if (count == 1)
				result->pos2.y = i / 4;
			else
				result->pos3.y = i / 4;
			count++;
		}
		i++;
	}
}

void					set_coordinates7(char *str, t_coordinates *result)
{
	if (ft_strequ(T19, str) == 1)
	{
		result->pos1.x = -1;
		result->pos2.x = 0;
		result->pos3.x = 0;
	}
}

void					set_coordinates6(char *str, t_coordinates *result)
{
	if (ft_strequ(T16, str) == 1)
	{
		result->pos1.x = -1;
		result->pos2.x = 0;
		result->pos3.x = 1;
	}
	else if (ft_strequ(T17, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = 1;
		result->pos3.x = 0;
	}
	else if (ft_strequ(T18, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 2;
		result->pos3.x = 1;
	}
	else
		set_coordinates7(str, result);
}

void					set_coordinates5(char *str, t_coordinates *result)
{
	if (ft_strequ(T13, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = 0;
		result->pos3.x = 1;
	}
	else if (ft_strequ(T14, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 2;
		result->pos3.x = 0;
	}
	else if (ft_strequ(T15, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 1;
		result->pos3.x = 1;
	}
	else
		set_coordinates6(str, result);
}

void					set_coordinates4(char *str, t_coordinates *result)
{
	if (ft_strequ(T10, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 2;
		result->pos3.x = 2;
	}
	else if (ft_strequ(T11, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = -1;
		result->pos3.x = 0;
	}
	else if (ft_strequ(T12, str) == 1)
	{
		result->pos1.x = -2;
		result->pos2.x = -1;
		result->pos3.x = 0;
	}
	else
		set_coordinates5(str, result);
}

void					set_coordinates3(char *str, t_coordinates *result)
{
	if (ft_strequ(T7, str) == 1)
	{
		result->pos1.x = -1;
		result->pos2.x = 0;
		result->pos3.x = -1;
	}
	else if (ft_strequ(T8, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = 1;
		result->pos3.x = 2;
	}
	else if (ft_strequ(T9, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 0;
		result->pos3.x = 0;
	}
	else
		set_coordinates4(str, result);
}

void					set_coordinates2(char *str, t_coordinates *result)
{
	if (ft_strequ(T4, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = 1;
		result->pos3.x = 1;
	}
	else if (ft_strequ(T5, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 1;
		result->pos3.x = 2;
	}
	else if (ft_strequ(T6, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = -1;
		result->pos3.x = 0;
	}
	else
		set_coordinates3(str, result);
}

void					set_coordinates(char *str, t_coordinates *result)
{
	if (ft_strequ(T1, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 2;
		result->pos3.x = 3;
	}
	else if (ft_strequ(T2, str) == 1)
	{
		result->pos1.x = 0;
		result->pos2.x = 0;
		result->pos3.x = 0;
	}
	else if (ft_strequ(T3, str) == 1)
	{
		result->pos1.x = 1;
		result->pos2.x = 0;
		result->pos3.x = 1;
	}
	else
		set_coordinates2(str, result);
	set_y_coordinates(str, result);
}

static t_coordinates	*generate_coordinates2(int id, t_coordinates *result)
{
	if (id == 10)
		set_coordinates(T10, result);
	else if (id == 11)
		set_coordinates(T11, result);
	else if (id == 12)
		set_coordinates(T12, result);
	else if (id == 13)
		set_coordinates(T13, result);
	else if (id == 14)
		set_coordinates(T14, result);
	else if (id == 15)
		set_coordinates(T15, result);
	else if (id == 16)
		set_coordinates(T16, result);
	else if (id == 17)
		set_coordinates(T17, result);
	else if (id == 18)
		set_coordinates(T18, result);
	else
		set_coordinates(T19, result);
	return (result);
}

t_coordinates			*generate_coordinates(int id)
{
	t_coordinates	*result;

	result = (t_coordinates*)malloc(sizeof(t_coordinates));
	if (id == 1)
		set_coordinates(T1, result);
	else if (id == 2)
		set_coordinates(T2, result);
	else if (id == 3)
		set_coordinates(T3, result);
	else if (id == 4)
		set_coordinates(T4, result);
	else if (id == 5)
		set_coordinates(T5, result);
	else if (id == 6)
		set_coordinates(T6, result);
	else if (id == 7)
		set_coordinates(T7, result);
	else if (id == 8)
		set_coordinates(T8, result);
	else if (id == 9)
		set_coordinates(T9, result);
	else
		result = generate_coordinates2(id, result);
	return (result);
}

t_coordinates			*find_coordinates(int id)
{
	static t_coordinates	**coordinate_table;

	if (coordinate_table == NULL)
		coordinate_table = (t_coordinates**)ft_memalloc(\
			sizeof(t_coordinates*) * N_UNIQUE_TETS);
	if (coordinate_table[id - 1] == NULL)
	{
		coordinate_table[id - 1] = (t_coordinates*)malloc(\
			sizeof(t_coordinates));
		coordinate_table[id - 1] = generate_coordinates(id);
	}
	return (coordinate_table[id - 1]);
}
