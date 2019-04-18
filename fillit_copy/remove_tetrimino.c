/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_tetrimino.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:59:18 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/05 13:56:36 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void    remove_tetrimino(int *tetrimino, unsigned char *index_field)
{
  index_field[tetrimino[0]] = '.';
  index_field[tetrimino[1]] = '.';
  index_field[tetrimino[2]] = '.';
  index_field[tetrimino[3]] = '.';
  tetrimino[7] = -1;
}
