/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_field.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:43:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/18 18:01:01 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned char	*make_field(int tet_amount, int **tet_array, int i)
{
	unsigned char	*field;

	field = (unsigned char *)ft_memdup("...\n...\n...\0", 180);
	if (tet_amount == 5 || tet_amount == 6)
		i = 2;
	else if (tet_amount >= 7 && tet_amount <= 9)
		i = 3;
	else if (tet_amount >= 10 && tet_amount <= 12)
		i = 4;
	else if (tet_amount >= 13 && tet_amount <= 16)
		i = 5;
	else if (tet_amount >= 17 && tet_amount <= 20)
		i = 6;
	else if (tet_amount >= 21 && tet_amount <= 25)
		i = 7;
	else if (tet_amount == 26)
		i = 8;
	field[170] = 255;
	while (i > 0)
	{
		expand_field(field, ft_linelen((char *)field), tet_array);
		i--;
	}
	field[170] = get_max_dots(tet_amount);
	return (field);
}
