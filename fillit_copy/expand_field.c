/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_field.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:44:28 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 17:45:10 by fmiceli       ########   odam.nl         */
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

void		expand_field(char *field, int linelen, int **array)
{
	int	i;
	int	j;

	linelen++;
	j = 1;
	i = linelen;
	ft_memset(field, '.', (linelen + 1) * linelen);
	while (j < linelen)
	{
		field[i] = '\n';
		i = i + (linelen + 1);
		j++;
	}
	field[i] = '\0';
	if (field[170] != -1)
	  field[170] += linelen * 2 - 1;
	adjust_tets_to_field(array);
}
