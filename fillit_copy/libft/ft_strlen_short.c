/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen_short.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccoers <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 13:32:26 by ccoers        #+#    #+#                 */
/*   Updated: 2019/04/05 13:32:54 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  ft_strlen_short(short *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
