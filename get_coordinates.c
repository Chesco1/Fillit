/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_coordinates.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:59:22 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/01 16:59:24 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_y_coordinates(char *str)
{
	int i;
	int count;
	int *coordinates;

	i = 1;
	count = 0;
	coordinates = (int *)malloc(sizeof(int) * 3);
	while (count < 3)
	{
		if (str[i] == '#')
		{
			coordinates[count] = i / 4;
			count++;
		}
		i++;
	}
	return (coordinates);
}

int		*get_x_coordinates(char *str)
{
	int i;
	int count;
	int *coordinates;

	i = 1;
	count = 0;
	coordinates = (int *)malloc(sizeof(int) * 3);
	while (count < 3)
	{
		if (str[i] == '#')
		{
			if (i % 4 == 0)
				coordinates[count] = 0;
			else if (i % 4 == 1)
				coordinates[count] = 1;
			else if (i % 4 == 2)
				coordinates[count] = 2;
			else
				coordinates[count] = 3;
			count++;
		}
		i++;
	}
	return (coordinates);
}

void	set_coordinates(t_coordinates *coords, char *str)
{
	int *x_coordinates;
	int *y_coordinates;

	x_coordinates = get_x_coordinates(str);
	y_coordinates = get_y_coordinates(str);
	t_coordinates
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