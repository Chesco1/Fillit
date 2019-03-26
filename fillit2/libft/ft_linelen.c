/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_linelen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:23:47 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 16:24:06 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_linelen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
