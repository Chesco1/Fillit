/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_field.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:43:02 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/26 02:19:32 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **make_field(int tet_amount)
{
  char **field;
  int linelen;
  int i;

  i = 0;
  linelen = ft_sqrt_ceil(tet_amount * 4);
  field = (char **)malloc(sizeof(char *) * linelen);
  while (i < linelen)
  {
    field[i] = (char *)malloc(sizeof(char) * linelen);
    ft_memset(field[i], '.', linelen);
    i++;
  }
  return(field);
}