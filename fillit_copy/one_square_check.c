/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   one_square_check.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 16:49:18 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/18 16:54:52 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	one_square_check(int **tet_array)
{
	if (tet_array[0][0] == 0 && tet_array[0][1] == 1 &&
		tet_array[0][2] == 4 && tet_array[0][3] == 5 &&
		tet_array[1] == NULL)
	{
		ft_putendl("AA\nAA");
		exit(0);
	}
}
