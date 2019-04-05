/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_linelen_short.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 13:34:30 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/05 13:34:49 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  ft_linelen_short(short *str)
{
    int  i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    return (i);
}
