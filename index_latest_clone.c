/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_latest_clone.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 22:38:25 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/18 17:22:01 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		index_latest_clone(int **tet_array, int *tetrimino, int i)
{
	if (i < 1)
		return (-1);
	i--;
	while (i >= 0)
	{
		if (ft_memcmp(tetrimino, tet_array[i], 4) == 0)
			return (i);
		i--;
	}
	return (-1);
}
