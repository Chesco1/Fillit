/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tets.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 19:16:23 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/22 19:20:49 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tets(int **tet_array)
{
	int i;

	i = 0;
	while (tet_array[i] != NULL)
	{
		free(tet_array[i]);
		i++;
	}
	free(tet_array[i]);
	free(tet_array);
}
