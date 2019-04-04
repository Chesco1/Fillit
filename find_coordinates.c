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
				result->y1 = i / 4;
			else if (count == 1)
				result->y2 = i / 4;
			else (count == 2)
				result->y3 = i / 4;
			count++;
		}
		i++;
	}
}

void					set_coordinates(char *str, t_coordinates *result)
{
	int i;
	int count;
	int start;

	i = 1;
	start = 0;
	count = 0;
	while (count < 3)
	{
		//TODO: Write non-shite
		// if (str[i] == '#')
		// {
		// 	if (i % 4 == 0)
		// 		coordinates[count] = 0;
		// 	else if (i % 4 == 1)
		// 		coordinates[count] = 1;
		// 	else if (i % 4 == 2)
		// 		coordinates[count] = 2;
		// 	else
		// 		coordinates[count] = 3;
		// 	count++;
		// }
		// i++;
		ft_read_from_abs_str(str);
	}
	set_y_coordinates(str, result);
}

static t_coordinates	*find_other_coordinates(int id, t_coordinates *result)
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

t_coordinates			*find_coordinates(int id)
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
		result = find_other_coordinates(id, result);
	return (result);
}



int		main(void)
{
	int i;
	int *coordinates;

	i = 0;
	coordinates = get_y_coordinates("##..##");
	ft_putnbr(coordinates[0]);
	ft_putchar('\n');
	ft_putnbr(coordinates[1]);
	ft_putchar('\n');
	ft_putnbr(coordinates[2]);
	ft_putchar('\n');
	return (0);
}