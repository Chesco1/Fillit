/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tetrimino.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:00:10 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/11 13:47:33 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void    place_tetrimino(int *tetrimino, unsigned char *index_field, int j)
{
	index_field[tetrimino[0]] = tetrimino[5];
	index_field[tetrimino[1]] = tetrimino[5];
	index_field[tetrimino[2]] = tetrimino[5];
	index_field[tetrimino[3]] = tetrimino[5];
	tetrimino[7] = j;
}
