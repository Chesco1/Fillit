/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tetrimino.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/23 18:00:10 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/03/25 15:49:18 by ccoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
