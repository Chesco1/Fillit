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

static int	*index_n_char(char *str, int c, size_t n)
{
	size_t	i;
	size_t	j;
	int		*array;

	i = 0;
	j = 0;
	array = (int *)malloc(sizeof(int) * n + 1);
	while (j < n && str[i] != '\0')
	{
		while (j < n && str[i] != c && str[i] != '\0')
			i++;
		if (j < n && str[i] != '\0')
		{
			array[j] = i;
			i++;
			j++;
		}
	}
	array[j] = -1;
	return (array);
}

int	ft_strequ_in(char const *s1, char const *s2, char *array)
{
	static int i = 0;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (ft_strcmp_ignore_nl(s1, s2) == 0)
	{
		array[i] = index_n_char((char *)s1, '#', 6);
		array[i][5] = 65 + i;
		array[i][6] = 0;
		i++;
		return (1);
	}
	return (0);
}
