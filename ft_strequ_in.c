/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ_in.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:51:19 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 17:51:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tet_identify2(char *str)
{
	if (ft_strequ(T12, str) == 1)
		return (12);
	else if (ft_strequ(T13, str) == 1)
		return (13);
	else if (ft_strequ(T14, str) == 1)
		return (14);
	else if (ft_strequ(T15, str) == 1)
		return (15);
	else if (ft_strequ(T16, str) == 1)
		return (16);
	else if (ft_strequ(T17, str) == 1)
		return (17);
	else if (ft_strequ(T18, str) == 1)
		return (18);
	else
		return (19);
}

static int	tet_identify(char *str)
{
	if (ft_strequ(T1, str) == 1)
		return (1);
	else if (ft_strequ(T2, str) == 1)
		return (2);
	else if (ft_strequ(T3, str) == 1)
		return (3);
	else if (ft_strequ(T4, str) == 1)
		return (4);
	else if (ft_strequ(T5, str) == 1)
		return (5);
	else if (ft_strequ(T6, str) == 1)
		return (6);
	else if (ft_strequ(T7, str) == 1)
		return (7);
	else if (ft_strequ(T8, str) == 1)
		return (8);
	else if (ft_strequ(T9, str) == 1)
		return (9);
	else if (ft_strequ(T10, str) == 1)
		return (10);
	else if (ft_strequ(T11, str) == 1)
		return (11);
	else
		return (tet_identify2(str));
}

int	ft_strequ_in(char const *s1, char const *s2, char *initial_tets)
{
	static int i = 0;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (ft_strcmp_ignore_nl(s1, s2) == 0)
	{
		initial_tets[i] = tet_identify((char *)s1);
		i++;
		return (1);
	}
	return (0);
}
