/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean_field.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 21:34:27 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/05 15:50:49 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_field(unsigned char *field, int **tet_array)
{
	int i;

	i = 0;
	while (field[i] != '\0')
	{
		if (field[i] != '\n')
			field[i] = '.';
		i++;
	}
	i = 0;
	while (tet_array[i] != NULL)
	  {
	    tet_array[i][7] = -1;
	    i++;
	  }
}
