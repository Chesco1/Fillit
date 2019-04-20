/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_move.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/20 16:35:25 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/20 16:35:26 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_max_x_offset(int row, t_pos *move, t_coordinates *offsets)
{
	int	max_x;

	max_x = move.y == row ? move.x : 0;
	max_x = ft_max(max_x, offsets.pos1->y == row ? offsets.pos1.x : 0);
	max_x = ft_max(max_x, offsets.pos2->y == row ? offsets.pos2.x : 0);
	max_x = ft_max(max_x, offsets.pos3->y == row ? offsets.pos3.x : 0);
	return (max_x);
}

static t_state	*first_move(\
	t_state *new_state, t_pos *move, t_coordinates *offsets, char c)
{
	char	*row;
	int		max_x;

	max_x = get_max_x_offset(0, move, offsets);
	row = (char *)malloc(sizeof(char) * max_x);
	row = ft_memset('.');
	if ()
	new_state->field_rows = ft_lstnew(row, max_x);
}

t_state			*do_move(\
	t_state *new_state, t_pos *move, t_coordinates *offsets, c)
{
	t_list	*row;
	int		y;
	int		x;

	y = 0;
	x = 0;
	row = new_state->field_rows;
	if (row == NULL)
		return (first_move(new_state, move, offsets, c));
	while (y < move.y)
	{
		row = row->next;
		y++;
	}
	return (new_state);
}
