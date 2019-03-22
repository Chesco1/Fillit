/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index_n_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:21:02 by ccoers        #+#    #+#                 */
/*   Updated: 2019/03/22 15:04:47 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*index_n_char(char *str, int c, size_t n)
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
