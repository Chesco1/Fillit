/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 19:05:27 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 01:58:59 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int	*str1;
	int	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (int *)s1;
	str2 = (int *)s2;
	while (str1[i] == str2[i] && i < n - 1)
	{;
		i++;
	}
	return (str1[i] - str2[i]);
}
