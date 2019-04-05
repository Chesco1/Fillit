/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tetrimino.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:00:10 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/28 17:24:43 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
void	place_tetrimino(int *tetrimino, char *index_field)
{
	int	i;

	i = 0;
	while (tetrimino[i] != -1)
	{
		index_field[tetrimino[i]] = tetrimino[5];
		i++;
	}
}

*/

void    place_tetrimino(int *tetrimino, short *index_field)
{
  index_field[tetrimino[0]] = tetrimino[5];
  index_field[tetrimino[1]] = tetrimino[5];
  index_field[tetrimino[2]] = tetrimino[5];
  index_field[tetrimino[3]] = tetrimino[5];
}
