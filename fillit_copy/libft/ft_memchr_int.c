/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 20:56:15 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/02 21:33:20 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_memchr_int(const void *s, int c, size_t n)
{
    if (ft_memchr(s, c, n) != NULL)
        return (ft_memchr(s, c, n) - s);
    return (1000);
}
