/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 17:36:28 by ccoers        #+#    #+#                 */
/*   Updated: 2019/02/20 19:53:14 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_int(const char *s, int c)
{
	if (ft_strchr(s, c) != NULL)
		return (ft_strchr(s, c) - s);
	return (-1);
}
