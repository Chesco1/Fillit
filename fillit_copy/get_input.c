/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_input.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:52:52 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 17:53:07 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*get_input(int fd)
{
	char	buf[(SIZE_TET * MAX_TETS) + 2];
	char	*input;
	int		ret;

	ret = read(fd, buf, (SIZE_TET * MAX_TETS) + 2);
	buf[ret] = '\0';
	input = ft_strnew(ft_strlen(buf) + 1);
	ft_strcpy(input, buf);
	return (input);
}
