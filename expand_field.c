/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:44:28 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/23 14:23:38 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	adjust_tets_to_field(int **array)
{
	int	i;
	int	j;
	int	k;

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

void		expand_field(unsigned char *field, int linelen, int **array)
{
	int	i;
	int	j;

	linelen++;
	i = linelen;
	j = 1;
	ft_memset(field, '.', (linelen + 1) * linelen);
	while (j < linelen)
	{
		field[i] = '\n';
		i = i + (linelen + 1);
		j++;
	}
	field[i] = '\0';
	if (MAX_DOTS != 255)
		MAX_DOTS += linelen * 2 - 1;
	STRLEN = (unsigned char)ft_strlen((char *)field);
	adjust_tets_to_field(array);
}
