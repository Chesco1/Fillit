/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_field.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:43:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 17:43:15 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*make_field(int tet_amount)
{
	char	*field;
	int		i;

	i = 0;
	field = ft_strnew(400);
	ft_memset(field, '.', 11);
	field[3] = '\n';
	field[7] = '\n';
	field[11] = '\0';
	return (field);
}
