/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ_in.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:51:19 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 00:46:00 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_strequ_in(char const *s1, char const *s2, int **tet_array)
{
	static int i = 0;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (ft_strcmp_ignore_nl(s1, s2) == 0)
	{
		tet_array[i] = index_n_char((char *)s1, '#', 8);
		tet_array[i][5] = 65 + i;
		tet_array[i][6] = index_latest_clone(tet_array, tet_array[i], i);
		tet_array[i][7] = 0;
		i++;
		return (1);
	}
	return (0);
}