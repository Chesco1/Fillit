/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_tets.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 21:56:37 by ccoers        #+#    #+#                 */
/*   Updated: 2019/03/26 21:56:39 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	convert_tets(int **tet_array)
{
	int i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		if (tet_array[i][6] == -1)
			tet_array[i][6] = 0;
		tet_array[i][7] = -1;
		i++;
	}
}