/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_move.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 15:26:39 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/04 15:26:40 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	get_move(\
	t_state *old_state, t_list *current_line, int id)
{
	t_coordinates	*coords;
	int				y_offset;
	int				i;
	int				x;

	coords = find_coordinates(id);
	x = current_line->LINE_LEN;
	y_offset = coords->pos1->y;
	i = 0;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(current_line->LINE_LEN - coords->pos1->x, x);
	y_offset = coords->pos2->y;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(current_line->LINE_LEN - coords->pos2->x, x);
	y_offset = coords->pos3->y;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(current_line->LINE_LEN - coords->pos3->x, x);
	return (x);
}