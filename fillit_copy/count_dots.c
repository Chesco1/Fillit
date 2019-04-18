/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_dots.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 14:53:45 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/18 17:22:47 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_dots(const unsigned char *field, const int *tetrimino)
{
	int i;
	int dots;

	i = 0;
	dots = 0;
	while (i <= (tetrimino[7] + tetrimino[3] - 1))
	{
		if (field[i] == '.')
			dots++;
		i++;
	}
	return (dots);
}
