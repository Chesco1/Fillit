/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp_ignore_nl.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 16:28:38 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/23 16:28:51 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_ignore_nl(const char *s1, const char *s2)
{
	size_t	i;
	char	*str;
	char	*str2;
	size_t	j;

	str = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	while ((str[i] == str2[j] && str[i] != '\0') || str2[j] == '\n')
	{
		if (str2[j] == '\n')
		{
			j++;
			continue ;
		}
		i++;
		j++;
	}
	return (str[i] - str2[j]);
}
