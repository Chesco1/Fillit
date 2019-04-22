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

int	get_line_len(char *line, int n)
{
	return (ft_memchr(line, '\0', n) - line);
}

int	get_move(\
	t_state *old_state, t_list *current_line, int id)
{
	t_coordinates	*coords;
	int				y_offset;
	int				i;
	int				max_x;
	int				x;

	coords = find_coordinates(id);
	max_x = old_state->field_width;
	x = 0;
	y_offset = coords.pos1->y;
	i = 0;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(get_line_len(current_line, max_x) - coords.pos1->x, x);
	y_offset = coords.pos2->y;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(get_line_len(current_line, max_x) - coords.pos2->x, x);
	y_offset = coords.pos3->y;
	while (i < y_offset)
		current_line = current_line->next;
	x = ft_max(get_line_len(current_line, max_x) - coords.pos3->x, x);
	return (x);
}
