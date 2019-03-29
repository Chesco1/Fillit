/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_tetrimino.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 17:59:18 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/28 17:25:07 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	remove_tetrimino(int *tetrimino, char *index_field)
{
	int i;

	i = 0;
	while (tetrimino[i] != -1)
	{
		index_field[tetrimino[i]] = '.';
		i++;
	}
	tetrimino[7] = -1;
	tetrimino[8] = 0;
}
