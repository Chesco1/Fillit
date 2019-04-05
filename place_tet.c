/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   place_tet.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 14:21:05 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/04/05 14:21:05 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	set_char(int *used_letters, int index)
{
	int		unused_letters_seen;
	int		letter;
	int 	bit_pointer;

	unused_letters_seen = 0;
	bit_pointer = 0x1;
	letter = 0;
	while (unused_letters_seen <= index)
	{
		if (~(*used_letters) & bit_pointer)
			unused_letters_seen++;
		if (unused_letters_seen == index)
			(*used_letters) |= bit_pointer;
		else
		{
			letter++;
			bit_pointer <<= 1;
		}
	}
	return ((unsigned char)(letter + 'A'));
}

t_state	*place_tet(\
	t_state *state, t_list *current_line, int tet_index, t_pos *move)
{
	t_state	*new_state;
	char	c;

	new_state = (t_state*)malloc(sizeof(t_state));
	new_state->used_letters = old_state->used_letters;
	c = set_char(&(new_state->used_letters), tet_index);
	return (new_state);
}
