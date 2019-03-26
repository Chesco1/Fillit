/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_field.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:43:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 00:18:38 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *make_field(int tet_amount, int **tet_array, int i)
{
        char    *field;

        field = ft_memdup("...\n...\n...\0", 200);
        if (tet_amount >= 2 && tet_amount <= 4)
          i = 1;
        else if (tet_amount == 5 || tet_amount == 6)
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
	while (i > 0)
          {
	    expand_field(field, ft_linelen(field), tet_array);
            i--;
          }
        return (field);
}
